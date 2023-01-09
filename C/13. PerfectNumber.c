/*
Perfect number : a positive integer that is equal to the sum of all its proper positive divisors
*/

#include <stdio.h>

int main(void)
{
    int i, num, sum = 1;
    printf("Enter a number : ");
    scanf("%d", &num);

    for(i = 2; i <= num / 2; i++){
        if(num % i == 0) sum += i;
    }

    if(sum == num) printf("%d is a perfect number\n", num);
    else printf("%d is not a perfect number\n", num);
    return 0;
}

/*
Enter a number : 28
28 is a perfect number
*/
