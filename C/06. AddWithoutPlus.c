#include <stdio.h>

int main(void)
{
    int num1, num2, sum;
    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);

    if(num1 < num2){
        num1 = num1 + num2;
        num2 = num1 - num2;
        num1 = num1 - num2;
    }

    while(num1 != 0 && num2 != 0){
        if(num2 > 0){
            num1++;
            num2--;
        }
        else{
            num1--;
            num2++;
        }
    }

    sum = (num1 != 0) ? num1 : num2;
    printf("Sum = %d\n", sum);
    return 0;
}

/*
Enter two numbers : -21 12
Sum = -9
*/
