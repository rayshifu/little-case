#include "rsf_common.h"
#include "vlstack.h"
#include "bignum.h"

#include <stdio.h>

char bn_init(STACK **st, char* o)
{
    int i;
    *st = st_init();
    
    for(i=0;i<strlen(o);i++)
        st_push(*st,rsf_atoi(o[i]));
    
    return 0;
}

STACK* bn_reverse(STACK *st)
{
   STACK *r = st_init();

   for(int i=st_gettopb(st)-1;i>=0;i--)
      st_push(r, st_pop(st));

   return r; 
}

void _add_with_carry(STACK *d, STACK *s, int carry)
{
   while(!st_isempty(s)){
       int v;

       v = st_pop(s) + carry;
       if(v >= 10){
           st_push(d, v%10);
           carry = 1;
       }else{
           st_push(d, v); 
           carry = 0;
       }
   }    
   if(carry == 1)
       st_push(d, 1);
}

STACK* bn_add(STACK *st1, STACK *st2)
{
    int i, carry=0;

    STACK *r = st_init();
  
    while(!st_isempty(st1) && !st_isempty(st2)){
        int v;
        v = st_pop(st1) + st_pop(st2) + carry;
        if(v >= 10){
           st_push(r, v%10); 
           carry = 1;
        }else{
           st_push(r, v); 
           carry = 0;
        }
    }
    
    if(!st_isempty(st1))
        _add_with_carry(r, st1, carry);
    else if(!st_isempty(st2))
        _add_with_carry(r, st2, carry);
    else
        if(carry == 1)
            st_push(r, 1);

    return r;
}

STACK* bn_sub(STACK *st1, STACK *st2)
{
    int i, borrow=0, flag=0;   // flag is always positive by default

    STACK *r = st_init();
  
    int v1, v2;

    while(!st_isempty(st1) && !st_isempty(st2)){
        v1 = st_pop(st1) - borrow; v2 = st_pop(st2);
        if(v1 < v2){
            v1 += 10;
            borrow = 1;
        }else
            borrow = 0;
        st_push(r, v1 - v2);
    }
    
    while(!st_isempty(st1)){
        if(borrow == 1)
            st_push(r, st_pop(st1) - borrow);
        else
            st_push(r, st_pop(st1));
    }

    while(!st_isempty(st2)){
        if(borrow == 1)
            st_push(r, st_pop(st2) - borrow);
        else
            st_push(r, st_pop(st2));
    }



    return r;
}

STACK* bn_mul(STACK *st1, STACK *st2)
{

}

STACK* bn_div(STACK *st1, STACK *st2)
{

}

void bn_free(STACK *_st)
{
   st_freeb(_st);
}
