#include<stdio.h>
#include<stdlib.h>

// ensures the OpenCL import works regardless of platform
#ifdef __APPLE__
	#include<OpenCL/opencl.h>
#else
	#include<CL/cl.h>
#endif

cl_kernel void vectorAddition(int* a, int* b, int* c) {
	int i = get_global_id(0);
	c[i] = a[i] + b[i];
}

int main() {
	int* a = (int*)malloc(10 * sizeof(int));
	int* b = (int*)malloc(10 * sizeof(int));
	int* c = (int*)malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		a[i] = i;
		b[i] = i;
	}

	vectorAddition(a, b, c);
}
