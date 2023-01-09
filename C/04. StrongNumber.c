/*
Strong number : a number in which the sum of factorials of individual digits is equal to the number itself
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

/*
Enter a number : 145
145 is a strong number
*/
