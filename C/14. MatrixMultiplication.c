#include <stdio.h>

int main(void)
{
    int arows, acols, brows, bcols;
    int i, j, k, sum;

    printf("Enter number of rows and columns of matrix a : ");
    scanf("%d %d", &arows, &acols);

    int a[arows][acols];
    printf("\nEnter matrix a :\n\n");
    for(i = 0; i < arows; i++){
        for(j = 0; j < acols; j++) scanf("%d", &a[i][j]);
    }

    printf("\nEnter number of rows and columns of matrix b : ");
    scanf("%d %d", &brows, &bcols);

    if(acols != brows){
        printf("\nSorry! a and b matrices are not multipliable\n");
        return 0;
    }

    int b[brows][bcols], c[arows][bcols];
    printf("\nEnter matrix b :\n\n");
    for(i = 0; i < brows; i++){
        for(j = 0; j < bcols; j++) scanf("%d", &b[i][j]);
    }

    for(i = 0; i < arows; i++){
        for(j = 0; j < bcols; j++){
            sum = 0;
            for(k = 0; k < acols; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    printf("\nProduct of a and b :\n\n");
    for(i = 0; i < arows; i++){
        for(j = 0; j < bcols; j++) printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}

/*
Enter number of rows and columns of matrix a : 3 3

Enter matrix a :

1 2 1
3 1 2
2 4 3

Enter number of rows and columns of matrix b : 3 3

Enter matrix b :

3 2 2
2 5 4
5 3 1

Product of a and b :

12 15 11
21 17 12
29 33 23
*/
