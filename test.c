#include"try-catch.h"
#include<stdio.h>
#include <assert.h>

#define CODE_1 1
#define CODE_2 2
#define CODE_3 3
exception_t e;

int test1() {
	jmp_buf* jb1 = exception_push();
	int val = 1;
	if (setjmp(*jb1)) {
		val = 2;
	} else {
		val = 0;
	}
	exception_pop();
	return val;
}

int test2() {
	jmp_buf* jb1 = exception_push();
	int val = 1;
	if (setjmp(*jb1)) {
		val = 0;
	} else {
		longjmp(*jb1, 1);
		val = 2;
	}
	exception_pop();
	return val;
}

int test3() {
	jmp_buf* jb1 = exception_push();
	int val = 1;
	if (setjmp(*jb1)) {
		val = 0;
	} else {
		jb1 = exception_push();
		val = 1;
		if (setjmp(*jb1)) {
			val = 4;
		} else {
			longjmp(*jb1, 1);
			val = 2;
		}
		exception_pop();

		jb1 = exception_top();
		longjmp(*jb1, 1);
	}
	exception_pop();
	return val;
}

int main() {
	int val = test1();
	if (val) {
		printf("error code test1: %d\n", val);
	}
	val = test2();
	if (val) {
		printf("error code test2: %d\n", val);
	}
	val = test3();
	if (val) {
		printf("error code test3: %d\n", val);
	}
	return 0;
}
