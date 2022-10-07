#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

bool isFull()
{
    if(top == MAX-1) return true;
    else return false;
}

bool isEmpty()
{
    if(top == -1) return true;
    else return false;
}

void push(char data)
{
    if(isFull()){
        printf("Stack overflow.\n");
        exit(1);
    }
    stack[++top] = data;
    return;
}

char pop()
{
    if(isEmpty()){
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack[top--];
}

bool isMatched(char a, char b)
{
    if(a == '[' && b == ']') return true;
    else if(a == '{' && b == '}') return true;
    else if(a == '(' && b == ')') return true;
    else return false;
}

bool isBalanced(char *str)
{
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            push(str[i]);
        }
        else if(str[i] == ']' || str[i] == '}' || str[i] == ')'){
            if(isEmpty()){
                printf("Right brackets are more than left brackets\n");
                return false;
            }
            else if(!isMatched(pop(), str[i])){
                printf("Mismatched brackets\n");
                return false;
            }
        }
    }
    if(isEmpty()) return true;
    else{
        printf("Left brackets are more than right brackets\n");
        return false;
    }
}

int main(void)
{
    char expr[MAX];
    printf("Enter the algebraic expression : ");
    gets(expr);
    printf("\n");
    if(isBalanced(expr)){
        printf("Brackets are well balanced\n");
    }
    return 0;
}
