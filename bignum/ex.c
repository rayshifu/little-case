#include <stdio.h>

#include "bignum.h"

void print_bignum(STACK *_st)
{
    char x;

    while(!st_isempty(_st))
      printf("%d", st_pop(_st));

    printf("\n");
}

int main(int argc, char** argv)
{
    STACK *result, *st1, *st2;

    if(argc != 3){
        printf("ERROR!\n");
        return 1;
    }

    bn_init(&st1, argv[1]);
    bn_init(&st2, argv[2]);
    result = bn_add(st1, st2);
    print_bignum(result);

    bn_free(st1);
    bn_free(st2);
    bn_free(result);

    return 0;
}

