#include <stdio.h>

int main(void)
{
    int base, exponent, expo;
    double power1 = 1, power2 = 1.0;
    printf("Enter base and exponent : ");
    scanf("%d %d", &base, &exponent);

    expo = exponent;
    if(expo > 0){
        while(expo != 0){
            power1 *= base;
            expo--;
        }
        printf("\n%d ^ %d = %g\n", base, exponent, power1);
    }
    else{
        while(expo != 0){
            power2 *= (1.0/base);
            expo++;
        }
        printf("\n%d ^ %d = %g\n", base, exponent, power2);
    }
    return 0;
}
