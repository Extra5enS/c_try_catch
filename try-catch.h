#ifndef TRY_CATCH_H 
#define TRY_CATCH_H

#include <setjmp.h>
#include <stdlib.h>

typedef struct {
	jmp_buf array[1024];
	int size;	
} exception_t;

jmp_buf* exception_push();
void exception_pop();
jmp_buf* exception_top();


#endif
