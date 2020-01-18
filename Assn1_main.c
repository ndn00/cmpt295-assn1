#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer, size_t);
void show_bits(int);
void show_int(int);
void show_float(float);
void show_pointer(void *) ;
int  mask_LSbits(int);

int main() {
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

/* Add your test cases here in order
   to test your new functions. */
    show_bits(ival);
    show_bits(-ival);
    printf("%d \n",mask_LSbits(2));
    printf("%d \n",mask_LSbits(15));
    printf("%d \n",mask_LSbits(33));
    printf("%d \n",mask_LSbits(0));

    return 0;

}