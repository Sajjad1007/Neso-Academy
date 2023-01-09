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

/*
Enter the number of terms : 20

Fibonacci Series : 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181
*/
