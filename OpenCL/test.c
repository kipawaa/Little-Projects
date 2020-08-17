#include<stdio.h>
#include<stdlib.h>
#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

#define arrSize 10

int main() {
	// create the vectors to be added
	int* a = (int*) malloc(arrSize * sizeof(int));
	int* b = (int*) malloc(arrSize * sizeof(int));
	int* c = (int*) malloc(arrSize * sizeof(int));

	// put values into vectors a and b
	for (int i = 0; i < arrSize; i++) {
		a[i] = i;
		b[i] = i;
	}
	for (int i = 0; i < arrSize; i++) {
		printf("a: %d\tb: %d\n", a[i], b[i]);
	}

	// max size of the cl file
	const size_t clFileSize = 0x100000;
	char* source = (char*) malloc(clFileSize);

	// open the cl file for reading (cl reads from files as text)
	FILE* clFile = fopen("test.cl", "r");

	// copy the code from the cl file to the string "source"
	fread(source, 1, clFileSize, clFile);

	// close the file again
	fclose(clFile);
	
	// determine available compute units
	cl_device_id device = NULL;
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	
	// create compute context
	cl_context context = clCreateContext(NULL, CL_DEVICE_TYPE_GPU, NULL, NULL, NULL, NULL);
	
	// create command queue
	cl_command_queue queue = clCreateCommandQueue(context, device, 0, NULL);

	// allocate buffer memory objects (this seems to be where you allocate GPU memory for the things you want to compute)
	cl_mem a_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, NULL);
	cl_mem b_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int),  NULL, NULL);
	cl_mem c_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, arrSize * sizeof(int), NULL, NULL);

	// write the data for computation to memory available to the compute device
	clEnqueueWriteBuffer(queue, a_obj, CL_TRUE, 0, arrSize * sizeof(int), &a, 0, NULL, NULL);
	clEnqueueWriteBuffer(queue, b_obj, CL_TRUE, 0, arrSize * sizeof(int), &b, 0, NULL, NULL);

	// create compute program
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source, &clFileSize, NULL);

	// build compute program executable
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

	// create the compute kernel
	cl_kernel kernel = clCreateKernel(program, "vectorAddition", NULL);

	// set the args values
	clSetKernelArg(kernel, 0, arrSize * sizeof(int), NULL);
	clSetKernelArg(kernel, 1, arrSize * sizeof(int), NULL);
	clSetKernelArg(kernel, 2, arrSize * sizeof(int), NULL);

	// globalSize is the size of the whole work object, localSize is how large a chunk of data is processed at once? not entirely sure, TODO
	const size_t globalSize = arrSize;
	const size_t localSize = 64;

	// execute the kernel
	clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);

	// read from the buffer to get the data post-computation
	clEnqueueReadBuffer(queue, c_obj, CL_TRUE, 0, arrSize * sizeof(int), &c, 0, NULL, NULL);
	
	// display the results
	for (int i = 0; i < arrSize; i++) {
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
