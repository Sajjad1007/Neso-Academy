#include <stdio.h>

int main(void)
{
    int num1, num2, sum, carry;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    while(num2 != 0){
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }

    printf("Sum = %d\n", sum);
    return 0;
}

/*
Enter two numbers : -21 12
Sum = -9
*/
