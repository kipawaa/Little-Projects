__kernel void checkFactor(__global int* num, __global int* factors) {
	int i = get_global_id(0);
	
	if (i && !(*(num) % i)) { // if i isn't 0 and i divides num
		factors[i] = 1;
	}
}
