#ifndef TRY_CATCH_H 
#define TRY_CATCH_H

#include <setjmp.h>
#include <stdlib.h>

typedef struct {
	jmp_buf* array;
	int size;	
	int cap;
} exception_t;

void exception_init(exception_t *pe);

void exception_new_point(exception_t *pe);
void exception_delete(exception_t *pe);
jmp_buf* exception_top(exception_t *pe);

void exception_free(exception_t *pe);

int try_catch(exception_t* pe, int* pclt, size_t size);
void try_catch_end(exception_t* pe);
void throw(exception_t* pe, int val);

#endif
