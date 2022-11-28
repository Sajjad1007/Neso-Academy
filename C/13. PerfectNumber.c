/*
A perfect number is a positive integer that is equal to the sum of all its proper positive divisors.
*/

#include <stdio.h>

int main(void)
{
    int i, num, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);

    for(i = 1; i < num; i++){
        if(num % i == 0) sum += i;
    }

    if(sum == num) printf("%d is a perfect number\n", num);
    else printf("%d is not a perfect number\n", num);
    return 0;
}
