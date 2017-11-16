#include "vlstack.h"

char _growup(STACK *st)
{
    STACK_BLOCK *sb;

    if(st == NULL)
        return 1;

    sb = malloc(sizeof(STACK_BLOCK));
    if(sb == NULL)
        return 2;

    sb->top = -1;         // -1 = empty
    sb->capacity  = 5;    // default capacity is 100
    sb->data = (char *)malloc(sizeof(char) * sb->capacity);  // default 100 items;
    sb->prev = st->tail;  // First stack block must point to NULL
    sb->next = NULL; 
    if(st->first == NULL)
        st->first = sb;
    st->tail = sb;
 
    return 0;
}

STACK* st_init()
{
    STACK *st = malloc(sizeof(STACK));

    if(st == NULL)
        return NULL;

    st->first = NULL;
    st->tail  = NULL;

    if(_growup(st) != 0)
        return NULL;
    
    return st;
}

char st_push(STACK *st, char data)
{
    if(st == NULL)
        return 1;

    if(st->tail->top == st->tail->capacity - 1)
        if(_growup(st) != 0)
             return 2;

    st->tail->data[++(st->tail->top)] = data;

    return 0;
}

char st_pop(STACK *st)
{
    if(st == NULL)
        return 1;
    
    if(st_isemptyb(st))
        st_freeb(st);
    
    return st->tail->data[(st->tail->top)--];
}

char st_isemptyb(STACK *st)
{
    if(st == NULL)
        return -1;

    if(st->tail->top <= -1)
        return 1;   // empty

    return 0; // NOT empty
}

char st_isempty(STACK *st)
{
//    if(st == NULL)
//        return -1;

    if(st->tail == NULL)
        return 1;
    if((st->tail->top == -1) && (st->first == st->tail))
        return 1;

    return 0;
}

// free currently stack block
char st_freeb(STACK *st)
{ 
    STACK_BLOCK *sb;

    if(st == NULL)
        return 1;

    if(st->tail == NULL)
        return 2;
    
    sb = st->tail->prev;
    free(st->tail->data);
    free(st->tail);
    st->tail = sb;
    
    return 0;
}

// free entiry stack
void st_frees(STACK *st)
{
    while(st->tail != NULL)
        st_freeb(st);
    free(st);
}

long st_getcapb(STACK *st)
{
    if(st == NULL)
        return -1;
    
    if(st->tail == NULL)
        return -2;

    return st->tail->capacity;
}

long st_gettopb(STACK *st)
{
    if(st == NULL)
        return -1;
    
    if(st->tail == NULL)
        return -2;

    return st->tail->top;
}
