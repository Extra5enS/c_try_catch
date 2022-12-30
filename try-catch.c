#include "try-catch.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

exception_t *exc = NULL;

void exception_init() {
	exc = calloc(1, sizeof(exception_t));
}

jmp_buf* exception_push() {
	printf("! EXCEPTION_PUSH !\n");
	if (exc == NULL) {
		exception_init();
	}
	printf("exc = %p -> {array = %p, size = %d}\n", exc, exc -> array, exc -> size);
	exc -> size++;
	return exception_top();
}

void exception_pop() {
	printf("! EXCEPTION_POP !\n");
	printf("exc = %p -> {array = %p, size = %d}\n", exc, exc -> array, exc -> size);
	assert(exc != NULL);
	exc -> size--;
}

jmp_buf* exception_top() {
	printf("! EXCEPTION_TOP !\n");
	if (exc == NULL) {
		exception_init();
	}
	printf("exc = %p -> {array = %p, size = %d}\n", exc, exc -> array, exc -> size);
	return &(exc -> array[exc -> size - 1]);
}


