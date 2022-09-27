#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int stack[MAX];
int top = -1;

bool isFull()
{
    if(top == MAX-1){
        return true;
    }
    else{
        return false;
    }
}

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
    if(isFull()){
        printf("Stack overflow.\n");
        exit(1);
    }
    stack[++top] = data;
    return;
}

int pop()
{
    return stack[top--];
}

void printPrimeFact(unsigned num)
{
    while(num % 2 == 0){
        push(2);
        num /= 2;
    }

    int i = 3;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num /= i;
        }
        i += 2;
    }

    while(!isEmpty()){
        printf("%u ", pop());
    }
    printf("\n");
    return;
}

int main(void)
{
    unsigned num;
    printf("Please enter a positive number : ");
    scanf("%u", &num);
    printf("\nPrime factors of %u in descending order : ", num);
    printPrimeFact(num);
    return 0;
}
