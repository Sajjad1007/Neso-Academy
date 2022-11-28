#include <stdio.h>

int main(void)
{
    int num1, num2;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    while(num2 != 0){
        num1++;
        num2--;
    }

    printf("Sum = %d\n", num1);
    return 0;
}
