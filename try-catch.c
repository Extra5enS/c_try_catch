#include "try-catch.h"
#include <stdio.h>

void exception_init() {
	exp.size = 0;
}

void exception_new_point() {
	exp.size++;
}

jmp_buf* exception_top() {
	return &(exp.array[exp.size - 1]);
}

void exception_delete() {
	exp.size--;
}

void exception_free() {} 

void throw() {
	longjmp(*exception_top(), 1);	
}

int try_catch() {
	return setjmp(*exception_top());
} 

void try_catch_end() {
	exception_delete();
}

char* exception_doc() {
	return "You can use only use throw there";
}