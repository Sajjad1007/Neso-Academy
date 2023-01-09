#include <stdio.h>

int main(void)
{
    int q, rem, bin, dec = 0, base = 1;
    printf("Enter a binary number : ");
    scanf("%d", &bin);

    q = bin;
    while(q != 0){
        rem = q % 10;
        dec += rem * base;
        base *= 2;
        q /= 10;
    }

    printf("Decimal equivalent of %d = %d\n", bin, dec);
    return 0;
}

/*
Enter a binary number : 11001011
Decimal equivalent of 11001011 = 203
*/
