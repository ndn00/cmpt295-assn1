/*
 * Name: Duy Nguyen
 * Student Number: 301379431
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdint.h> //for SIZE_MAX
//# define SIZE_MAX		(18446744073709551615UL)  //alternative macro for SIZE_MAX

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;

    for (i = 0; i < len; i++)
		printf(" %p %.2x", start+i, *(start+i)); 
    printf("\n");	
}

void show_int(int x) {
	printf("\nival = %d\n", x); 
    show_bytes((byte_pointer) &x, sizeof(int)); 
}

void show_float(float x) {
    printf("fval = %f\n", x); 	
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	printf("pval = %p\n", x); 
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int bit_pattern(int x) {    //generate bitpatern from decimals
    int pos = 0;
    int pow = 1;
    int ret = 0;
    for(pos; pos < 8; ++pos){
        ret += (x%2) * pow;
        x/=2;
        pow*=10;
    }
    return ret;
}
void show_bits(int x) {
    byte_pointer start = &x;
    size_t i;
    //organizing bitpaterns LSB -> MSB
    for (i = sizeof(int)-1; i != SIZE_MAX; i--){    //size_t wrap around after 0 to SIZE_MAX
        int ret =  bit_pattern(*(start+i));
        printf("%.8d", ret ? ret : 0);  //print bitpattern of a byte
    }
    printf("\n");	
}
int mask_LSbits(int n) {
    return n>=sizeof(int)*8 ? -1 :  //edge case: w 1's bitpattern is -1 in Two's C
            n<=0 ? 0 :              //edge case: w 0's bitpattern is 0 in Two's C
            ((unsigned)(-1) >> (sizeof(int)*8-n));  //logical right shift (w-n) bits by casting to unsigned
}