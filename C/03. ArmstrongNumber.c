/*
Armstrong number : a number of n digits, where multiplying each digit by itself n times and adding them all results the same number
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int q, num, rem, cnt = 1, res = 0;
    printf("Enter a number : ");
    scanf("%d", &num);

    q = num;
    while(q /= 10) cnt++;

    q = num;
    while(q != 0){
        rem = q % 10;
        res += pow(rem, cnt);
        q /= 10;
    }

    if(res == num) printf("%d is an armstrong number\n", num);
    else printf("%d is not an armstrong number\n", num);
    return 0;
}

/*
Enter a number : 371
371 is an armstrong number
*/
