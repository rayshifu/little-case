#ifndef RSF_BIGNUM_H
#define RSF_BIGNUM_H

#include <string.h>
#include "vlstack.h"

char bn_init(STACK **st, char* o);
STACK* bn_reverse(STACK *st1);
STACK* bn_add(STACK *st1, STACK *st2);
STACK* bn_sub(STACK *st1, STACK *st2);
STACK* bn_mul(STACK *st1, STACK *st2);
STACK* bn_div(STACK *st1, STACK *st2);
void bn_free(STACK *st);

#endif

