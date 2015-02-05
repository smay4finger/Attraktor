#include <stdlib.h>
#include <stdio.h> 
#include <stdint.h>
#include <assert.h>

typedef uint32_t FP;
#define RADIX 20
#define FP(x) ((FP)((x) * ((FP)1<<RADIX)))

FP FP_mul(FP a, FP b)
{
    return (a * b) >> RADIX;
}

FP FP_div(FP a, FP b)
{
    return (a << RADIX) / b;
}

FP FP_add(FP a, FP b)
{
    return (a + b);
}

FP FP_sub(FP a, FP b)
{
    return (a - b);
}


void test_constants()
{
    printf("0x%x\n", FP(5/8.0));

    assert(FP(3) == 0xa000);
    assert(FP(3.0) == 0x3000);


    assert(FP(5/8.0) == FP_div(FP(5), FP(8)));
    assert(FP(3.5 * 2) == FP_mul(FP(3.5), FP(2)));
}


int main(int argc, char** argv)
{
    test_constants();
}

