#include "try-catch.h"
#include <stdio.h>

void exception_init(exception_t *pe) {
	pe -> array = NULL;
	pe -> size = 0;	
	pe -> cap = 0;
}


void exception_new_point(exception_t *pe) {
	if (pe -> size == pe -> cap) {
		pe -> cap = (pe -> cap + 1) * 2;
		pe -> array = realloc(pe -> array, pe -> cap * sizeof(jmp_buf));
	}
	pe -> size++;
}

jmp_buf* exception_top(exception_t *pe) {
	return &(pe -> array[pe -> size - 1]);
}

void exception_delete(exception_t *pe) {
	pe -> size--;
}

void exception_free(exception_t *pe) {
	free(pe -> array);
}

void throw(exception_t* pe, int val) {
	longjmp(*exception_top(pe), val);	
}

int try_catch(exception_t* pe, int* vals, size_t size) {
	exception_new_point(pe);
	printf("try_catch: pe -> size = %d\n", pe -> size);
	int val = setjmp(*exception_top(pe));
	if(val) {
		// we try to find this val in list
		for (int i = 0; i < size; i++) {
			if(val == vals[i]) {
				printf("I have found val = %d\n", val);
				return val;
			}
		}
		// we did't find, so we throw it in prev env
		printf("throw out\n");
		exception_delete(pe);
		throw(pe, val);
	}
	return 0;
}

void try_catch_end(exception_t* pe) {
	exception_delete(pe);
}

