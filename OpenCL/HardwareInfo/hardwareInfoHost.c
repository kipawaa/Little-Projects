#include<stdio.h>
#include<stdlib.h>
#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

#define arrSize 100000

int main() {
	cl_uint numPlatforms;
	clGetPlatformIDs(0, NULL, &numPlatforms); // requests 0 platforms but gathers the number available
	
	cl_platform_id* platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
	
	clGetPlatformIDs(numPlatforms, platforms, NULL); // store all of the available platforms
	
	for (int i = 0 ; i < numPlatforms; i++) {
		// determine the platform name
		char* platformName = (char*) malloc(1024 * sizeof(char));
		clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(platformName), platformName, NULL);

		// output platform name
		printf("Platform name: %s\n", platformName);
		
		// determine devices
		cl_uint numDevices;
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices); // determines the number of devices available
		cl_device_id* devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
		clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL); // store the available devices
		
		printf("platform devices:\n");

		// print device info
		for (int j = 0; j < numDevices; j++) {
			char* deviceName = (char*) malloc(1024 * sizeof(char));
			cl_uint maxComputeUnits;
			clGetDeviceInfo(devices[j], CL_DEVICE_NAME, sizeof(deviceName), deviceName, NULL); // get device name
			clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(maxComputeUnits), &maxComputeUnits, NULL);
			printf("device %d: %s, compute units: %d\n", j, deviceName, maxComputeUnits);
		}
	}
}
