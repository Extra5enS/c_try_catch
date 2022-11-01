#include"try-catch.h"
#include<stdio.h>

#define CODE_1 1
#define CODE_2 2
#define CODE_3 3
exception_t e;

int test1() {
	int a[] = {CODE_1, CODE_2, CODE_3};
	try_catch(&e, a, 3);
	try_catch_end(&e);
	return 0;
}


int test2() {
	int a[] = {CODE_1, CODE_2, CODE_3};
	int val = try_catch(&e, a, 3);
	if(val) {
		if(val != CODE_1) {
			return val;
		}	
	} else {
		throw(&e, CODE_1);
	}
	try_catch_end(&e);
	
	try_catch(&e, a, 3);
	if(val) {
		if(val != CODE_2) {
			return val;
		}	
	} else {
		throw(&e, CODE_2);
	}
	try_catch_end(&e);
	try_catch(&e, a, 3);
	if(val) {
		if(val != CODE_3) {
			return val;
		}	
	} else {
		throw(&e, CODE_3);
	}
	try_catch_end(&e);
	return 0;
}

int test3() {
	int a[] = {CODE_1, CODE_2, CODE_3};
	int val = try_catch(&e, &a[0], 1);
	if(val) {
		return CODE_1;
	} else {
		val = try_catch(&e, &a[1], 1);
		if(val) {
			return 0; // correct catch
		} else {
			val = try_catch(&e, &a[2], 1);
			if(val) {
				return CODE_3;
			} else {
				throw(&e, CODE_2);
			}	
			try_catch_end(&e);

		}	
		try_catch_end(&e);

	}	
	try_catch_end(&e);
	return 0;
}

int main() {
	exception_init(&e);
	test1();
	int val = test2();
	if (val) {
		printf("error code test2: %d\n", val);
	}
	val = test3();
	if (val) {
		printf("error code test3: %d\n", val);
	}
	return 0;
}
