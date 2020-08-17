#include<stdio.h>
#include<stdlib.h>
#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

#define arrSize 100000

int main() {
	// create the vectors to be added
	int* a = (int*) malloc(arrSize * sizeof(int));
	int* b = (int*) malloc(arrSize * sizeof(int));
	int* c = (int*) malloc(arrSize * sizeof(int));

	// put values into vectors a and b
	for (int i = 0; i < arrSize; i++) {
		a[i] = 1;
		b[i] = 1;
	}
	
	// max size of the cl file
	const size_t clFileSize = 0x100000;
	char* source = (char*) malloc(clFileSize);

	// open the .cl file for reading (cl reads from files as text)
	FILE* clFile = fopen("vectorAdditionKernel.cl", "r");

	// copy the text from the cl file to the string "source"
	fread(source, 1, clFileSize, clFile);

	// close the .cl file
	fclose(clFile);
	
	// variables to store platform and device information
	cl_platform_id platform = NULL;
	cl_device_id device = NULL; // can be an array if multiple devices will be used 

	cl_uint numDevices;
	cl_uint numPlatforms;

	// function return holder and error code retainer
	cl_int ret;

	// automatically determines the platform (AMD, nVidia etc.) and number of platforms being used (1 is requested by the first parameter)
	ret = clGetPlatformIDs(1, &platform, &numPlatforms);
	
	// determine devices and number of devices used (one GPU device is requested, as per 2nd and 3rd parameters) 
					// (devices can only be accessed if they are on the same platform as is passed in here (if platform is AMD but an intel CPU is desired, both platforms must be loaded))
	ret = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, &numDevices);
	
	// create compute context
	cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &ret);
	
	// create command queue
	cl_command_queue queue = clCreateCommandQueue(context, device, 0, &ret);

	// allocate buffer memory objects (this seems to be where you allocate GPU memory for the things you want to compute)
	cl_mem a_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, &ret); // read from a
	cl_mem b_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, &ret); // read from b
	cl_mem c_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, arrSize * sizeof(int), NULL, &ret); // write to c

	// write the data for computation to memory available to the compute device (vector c does not get a write buffer since it only needs to be read from, not written to)
	ret = clEnqueueWriteBuffer(queue, a_obj, CL_TRUE, 0, sizeof(int) * arrSize, a, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(queue, b_obj, CL_TRUE, 0, sizeof(int) * arrSize, b, 0, NULL, NULL);

	// read program from .cl document as strings
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source, &clFileSize, &ret);

	// compile OCL program
	ret = clBuildProgram(program, 1, &device, NULL, NULL, NULL);

	// create compute kernel
	cl_kernel kernel = clCreateKernel(program, "vectorAddition", &ret);

	// set kernel arguments
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_obj);

	// globalSize is the size of the whole work object, localSize is how large a chunk of data is processed by each work-group? not entirely sure, TODO
	const size_t globalSize = arrSize; // number of components in each vector
	const size_t localSize = 1; // number of components each thread needs to access at a time (for vector addition, only one component of each vector needs to be accessed)

	// execute the kernel
	ret = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);

	// read from the kernel buffer to get the data post-computation
	ret = clEnqueueReadBuffer(queue, c_obj, CL_TRUE, 0, arrSize * sizeof(int), c, 0, NULL, NULL);
	
	// clean up the buffers and everything associated with the OCL program
	clFlush(queue);
	clFinish(queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);
	clReleaseMemObject(a_obj);
	clReleaseMemObject(b_obj);
	clReleaseMemObject(c_obj);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);

	free(a);
	free(b);
	free(c);
}
