#include <stdio.h>
#include <stdbool.h>

#define MAX 32

int stack[MAX];
int top = -1;

bool isEmpty()
{
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(int data)
{
    stack[++top] = data;
    return;
}

int pop()
{
    return stack[top--];
}

void printBinary(unsigned num)
{
    if(num == 0){
        printf("0\n");
        return;
    }
    while(num != 0){
        push(num % 2);
        num /= 2;
    }
    while(!isEmpty()){
        printf("%u", pop());
    }
    printf("\n");
    return;
}

int main(void)
{
    unsigned num;
    printf("Enter a positive decimal number : ");
    scanf("%u", &num);
    printf("\nBinary equivalent of %u = ", num);
    printBinary(num);
    return 0;
}
