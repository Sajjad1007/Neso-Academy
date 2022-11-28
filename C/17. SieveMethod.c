#include <stdio.h>
#include <math.h>

void crossout(int ara[], int num, int k)
{
    if(ara[k] == 1) return; //k has been crossed out already
    for(int l = 2*k; l <= num; l += k) ara[l] = 1; //multiples of k will be crossed out but k will not
    return;
}

int main(void)
{
    int num, cnt = 0;
    printf("Enter the limit : ");
    scanf("%d", &num);
    int ara[num+1];

    for(int i = 1; i <= num; i++) ara[i] = i; //ara[0] will not be used anywhere in the program
    for(int k = 2; k <= sqrt(num); k++)
        crossout(ara, num, k); //the multiples of k is crossing out

    printf("\nThe prime numbers between 1 and %d :\n\n", num);
    for(int k = 2; k <= num; k++)
        if(ara[k] != 1){ //that means k has not been crossed out
            printf("%d ", ara[k]);
            cnt++; //prime counter is incremented
        }
    printf("\n\nTotal prime numbers = %d\n", cnt);
    return 0;
}
