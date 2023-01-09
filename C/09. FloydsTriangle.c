#include <stdio.h>

int main(void)
{
    int i, j, n, cnt = 1;
    printf("Enter number of rows : ");
    scanf("%d", &n);
    printf("\n");

    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++) printf(" %d", cnt++);
        printf("\n");
    }
    return 0;
}

/*
Enter number of rows : 4

 1
 2 3
 4 5 6
 7 8 9 10
*/
