#ifndef RSF_VLSTACK_H
#define RSF_VLSTACK_H

#include <stdlib.h>

#define ST_E_HEADNULL   10
#define ST_E_GROWUPFAIL 11
#define ST_E_HEADEMPTY  12
#define ST_E_NOERR      0

typedef struct _STACK_BLOCK{
    long top;    // Point to the top item of stack block
    long capacity;    // Capacity of the stack
    char *data;  // data array
    struct _STACK_BLOCK* prev; // Previously stack block
    struct _STACK_BLOCK* next; // Next stack block
}STACK_BLOCK;

typedef struct{
    STACK_BLOCK* first;
    STACK_BLOCK* tail;   // Point to the CURRENTLY used stack block
}STACK;

STACK* st_init();
char st_push(STACK *st, char data);
char st_pop(STACK *st);
char st_isemptyb(STACK *st);
char st_isempty(STACK *st);
char st_freeb(STACK *st);
void st_frees(STACK *st);
long st_getcapb(STACK *st);
long st_gettopb(STACK *st);



#endif
