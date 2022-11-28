#include <stdio.h>

int main(void)
{
    int num, q, res = 0, rem;
    printf("Enter a number : ");
    scanf("%d", &num);

    q = num;
    while(q != 0){
        rem = q % 10;
        res = res*10 + rem;
        q /= 10;
    }

    if(res == num) printf("%d is a palindrome\n", num);
    else printf("%d is not a palindrome\n", num);
    return 0;
}
