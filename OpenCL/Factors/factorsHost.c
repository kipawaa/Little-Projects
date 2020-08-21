#include<stdio.h>
#include<stdlib.h>

#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

int main() {
	// determine which number the user would like the factors of
	int* num = (int*)malloc(sizeof(int));
	printf("enter a number to determine factors: ");
	scanf("%d", num);

	// store the factors of num
	int* factors = (int*)calloc(*(num), sizeof(int));
	
	// max size of OCL file and string to store the data within
	const size_t clFileSize = 0x100000;
	char* clSource = (char*)malloc(clFileSize);

	// open the OCL source file for reading
	FILE* clFile = fopen("factorsKernel.cl", "r");

	// read the code from OCL source file
	fread(clSource, 1, clFileSize, clFile);

	// close the OCL source file
	fclose(clFile);

	// check if source file has been read successfully
	if (!clSource) {
		printf("source file could not be read\n");
		return 0;
	}

	// store platform and device
	cl_platform_id platform = NULL;
	cl_device_id device = NULL;

	cl_uint numDevices;
	cl_uint numPlatforms;

	// stores return values from OCL functions
	cl_int ret;

	// get an available platform
	ret = clGetPlatformIDs(1, &platform, &numPlatforms);

	// ensure a platform is found
	if (!platform) {
		printf("no platforms found!\n");
		return 0;
	}

	// get a GPU for computing
	ret = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, &numDevices);
	
	// ensure a device is found
	if (!device) {
		printf("no device found!\n");
		return 0;
	}

	// create context
	cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, &ret);

	// create command queue
	cl_command_queue queue = clCreateCommandQueue(context, device, 0, &ret);
	// read program from source
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&clSource, &clFileSize, &ret);
	
	// compile program
	ret = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
	
	// create compute kernel
	cl_kernel kernel = clCreateKernel(program, "checkFactor", &ret);
	
	// create memory buffers
	cl_mem num_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);
	cl_mem factors_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, *(num) * sizeof(int), NULL, &ret);
	
	// run compute program 1000 times to determine average program time for comparison with serial approach
	for (int iterations = 0; iterations < 1000; iterations++) {
		// write data to buffers
		ret = clEnqueueWriteBuffer(queue, num_obj, CL_TRUE, 0, sizeof(int), num, 0, NULL, NULL);
		
		// set kernel arguments
		ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&num_obj);
		ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&factors_obj);

		// set workgroup sizes
		const size_t globalSize = *(num);
		const size_t localSize = 1;

		// execute kernel
		ret = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize, 0, NULL, NULL);

		// read from buffer to determine factors
		ret = clEnqueueReadBuffer(queue, factors_obj, CL_TRUE, 0, *(num) * sizeof(int), factors, 0, NULL, NULL);
	}

	printf("complete.\n");

	// clean up the buffers and everything associated with the OCL program
	clFlush(queue);
	clFinish(queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);
	clReleaseMemObject(num_obj);
	clReleaseMemObject(factors_obj);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);

	free(factors);
	free(num);
}
