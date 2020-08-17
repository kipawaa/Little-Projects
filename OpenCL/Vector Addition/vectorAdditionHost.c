#include<stdio.h>
#include<stdlib.h>
#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

#define arrSize 1024

int main() {
	// create the vectors to be added
	int* a = (int*) malloc(arrSize * sizeof(int));
	int* b = (int*) malloc(arrSize * sizeof(int));
	int* c = (int*) malloc(arrSize * sizeof(int));

	// put values into vectors a and b
	for (int i = 0; i < arrSize; i++) {
		a[i] = i + 1;
		b[i] = i + 1;
	}

	printf("arrays created.\n");
	
	// max size of the cl file
	const size_t clFileSize = 0x100000;
	char* source = (char*) malloc(clFileSize);

	// open the cl file for reading (cl reads from files as text)
	FILE* clFile = fopen("vectorAdditionKernel.cl", "r");

	// copy the code from the cl file to the string "source"
	fread(source, 1, clFileSize, clFile);

	// close the file again
	fclose(clFile);
	
	printf("file read.\n");

	// platform and device information
	cl_platform_id platform = NULL;
	cl_device_id device = NULL;

	cl_uint numDevices;
	cl_uint numPlatforms;

	// function return holder and error code retainer
	cl_int ret;

	// determine platforms
	ret = clGetPlatformIDs(1, &platform, &numPlatforms);
	
	// determine devices
	ret = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, &numDevices);
	
	printf("platform and device information collected.\n");

	// create compute context
	cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &ret);
	
	// create command queue
	cl_command_queue queue = clCreateCommandQueue(context, device, 0, &ret);

	printf("context and queue created.\n");

	// allocate buffer memory objects (this seems to be where you allocate GPU memory for the things you want to compute)
	cl_mem a_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, &ret); // read from a
	cl_mem b_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, &ret); // read from b
	cl_mem c_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, arrSize * sizeof(int), NULL, &ret); // write to c

	printf("memory objects created.\n");

	// write the data for computation to memory available to the compute device
	ret = clEnqueueWriteBuffer(queue, a_obj, CL_TRUE, 0, sizeof(int) * arrSize, a, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(queue, b_obj, CL_TRUE, 0, sizeof(int) * arrSize, b, 0, NULL, NULL);

	printf("write buffers created\n");

	// create compute program
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source, &clFileSize, &ret);

	// build compute program executable
	ret = clBuildProgram(program, 1, &device, NULL, NULL, NULL);

	// create the compute kernel
	cl_kernel kernel = clCreateKernel(program, "vectorAddition", &ret);

	// set the args values
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_obj);

	// globalSize is the size of the whole work object, localSize is how large a chunk of data is processed at once? not entirely sure, TODO
	const size_t globalSize = arrSize;
	const size_t localSize = 64;

	// execute the kernel
	ret = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);

	// read from the buffer to get the data post-computation
	ret = clEnqueueReadBuffer(queue, c_obj, CL_TRUE, 0, arrSize * sizeof(int), c, 0, NULL, NULL);
	
	// display the results
	for (int i = 0; i < arrSize; i+= 100) {
		printf("%d: %d\n", i, c[i]);
	}

	printf("cleaning OpenCL stuff...\n");
	
	// clean up the buffers and everything associated with the CL program
	clFlush(queue);
	clFinish(queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);
	clReleaseMemObject(a_obj);
	clReleaseMemObject(b_obj);
	clReleaseMemObject(c_obj);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);

	printf("freeing memory...\n");
	free(a);
	free(b);
	free(c);
}
