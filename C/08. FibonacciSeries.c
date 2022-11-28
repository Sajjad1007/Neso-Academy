#include <stdio.h>

int main(void)
{
    int i, a, b, num, res;
    printf("Enter the number of terms : ");
    scanf("%d", &num);

    a = 0;
    b = 1;
    printf("\nFibonacci Series :");

    for(i = 1; i <= num; i++){
        printf(" %d", a);
        res = a + b;
        a = b;
        b = res;
    }
    printf("\n");
    return 0;
}
