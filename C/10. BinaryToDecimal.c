#include <stdio.h>

int main(void)
{
    int num, bin, dec = 0, base = 1, rem;
    printf("Enter a binary number : ");
    scanf("%d", &bin);

    num = bin;
    while(num != 0){
        rem = num % 10;
        dec += rem*base;
        base *= 2;
        num /= 10;
    }

    printf("Decimal equivalent of %d = %d\n", bin, dec);
    return 0;
}
