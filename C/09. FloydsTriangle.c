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
