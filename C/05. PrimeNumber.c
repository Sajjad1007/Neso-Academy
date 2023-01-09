#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    int i, num, root;
    bool flag = false;
    printf("Enter a number : ");
    scanf("%d", &num);

    root = ceil(sqrt(num));

    if(num == 2 || num == 3);
    else if(num % 2 == 0) flag = true;
    else{
        for(i = 3; i <= root; i += 2){
            if(num % i == 0){
                flag = true;
                break;
            }
        }
    }

    if(flag == false && num != 1) printf("%d is a prime number\n", num);
    else printf("%d is not a prime number\n", num);
    return 0;
}

/*
Enter a number : 31
31 is a prime number
*/
