/*
Infix means that the operator is written in between two operands, postfix means that the operator is written after two operands
computers prefer postfix expressions instead of infix expressions
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX]; //first the operators, then the operands will be pushed onto the stack
char infix[MAX];
char postfix[MAX];
int top = -1;

bool isEmpty()
{
    if(top == -1) return true;
    else return false;
}

void push(int val)
{
    stack[++top] = val;
    return;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

bool isSpace(char c)
{
    if(c == ' ' || c == '\t') return true;
    else return false;
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '^':
        return 3;

    case '/':
    case '*':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

void infixToPostfix()
{
    int i = 0, j = 0;
    char symbol, next;

    while(i < strlen(infix)){
        symbol = infix[i++];
        if(!isSpace(symbol)){
            switch(symbol)
            {
            case '(':
                push(symbol);
                break;

            case ')':
                next = pop();
                while(next != '('){
                    postfix[j++] = next;
                    next = pop();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && (precedence(peek()) >= precedence(symbol))){
                    if(symbol == '^') break;
                    postfix[j++] = pop();
                }
                push(symbol);
                break;

            default:
                postfix[j++] = symbol;
                break;
            }
        }
    }

    while(!isEmpty()) postfix[j++] = pop(); //the stack becomes empty
    postfix[j] = '\0';
    return;
}

int postfixEvaluation()
{
    int i = 0, a, b;
    while(i < strlen(postfix)){
        if(postfix[i] >= '0' && postfix[i] <= '9') push(postfix[i++] - '0');
        else{
            b = pop();
            a = pop();

            switch(postfix[i++])
            {
            case '+':
                push(a + b);
                break;

            case '-':
                push(a - b);
                break;

            case '*':
                push(a * b);
                break;

            case '/':
                push(a / b);
                break;

            case '^': //the associativity of this operator is right to left
                push(pow(a, b));
                break;
            }
        }
    }
    return pop();
}

int main(void)
{
    int result;
    printf("Enter the infix expression : ");
    gets(infix);
    infixToPostfix();
    result = postfixEvaluation();
    printf("\nThe equivalent postfix expression : %s\n", postfix);
    printf("The result obtained after postfix evaluation : %d\n", result);
    return 0;
}

/*
Enter the infix expression : (8+7)*(6-3)/9+(2*7-4)/5

The equivalent postfix expression : 87+63-*9/27*4-5/+
The result obtained after postfix evaluation : 7
*/
