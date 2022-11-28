/*
A strong number is a number in which the sum of factorial of individual digits of a number
is equal to the original number.
*/

#include <stdio.h>

int main(void)
{
    int i, q, num, rem, fact, res = 0;
    printf("Enter a number : ");
    scanf("%d", &num);

    q = num;
    while(q != 0){
        rem = q % 10;
        fact = 1;

        for(i = 1; i <= rem; i++) fact *= i;
        res += fact;
        q /= 10;
    }

    if(res == num) printf("%d is a strong number\n", num);
    else printf("%d is not a strong number\n", num);
    return 0;
}
