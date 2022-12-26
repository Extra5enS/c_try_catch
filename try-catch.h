#ifndef TRY_CATCH_H 
#define TRY_CATCH_H

#include <setjmp.h>
#include <stdlib.h>

typedef struct {
	jmp_buf array[1024];
	size_t size;
} exception_t;

static exception_t exp;

void exception_init();

void exception_new_point();
void exception_delete();
jmp_buf* exception_top();

void exception_free();

int try_catch();
void try_catch_end();
void throw();

#endif
