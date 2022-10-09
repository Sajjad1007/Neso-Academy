#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

bool isSFull();
bool isSEmpty();
void push(int);
int pop();
void enqueue(int);
int dequeue();
void reverseStack();
void printStack();

int stack[MAX];
int queue[MAX];
int top = -1;
int front = -1;
int rear = -1;

int main(void)
{
    int data;
    printf("Enter %d elements in the stack : ", MAX);
    for(int i = 1; i <= MAX; i++){
        scanf("%d", &data);
        push(data);
    }
    printf("\nBefore reversing, the stack : ");
    printStack();
    reverseStack();
    printf("After reversing, the stack : ");
    printStack();
    return 0;
}

bool isSEmpty()
{
    if(top == -1) return true;
    else return false;
}

bool isSFull()
{
    if(top == MAX-1) return true;
    else return false;
}

void push(int data)
{
    if(isSFull()){
        printf("Stack overflow.\n");
        exit(1);
    }
    stack[++top] = data;
    return;
}

int pop()
{
    if(isSEmpty()){
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack[top--];
}

void enqueue(int data)
{
    if(front == -1) front = 0;
    queue[++rear] = data;
    return;
}

int dequeue()
{
    return queue[front++];
}

void reverseStack()
{
    //pop elements from stack, then enqueue them onto queue
    while(!isSEmpty()) enqueue(pop());
    //dequeue elements from queue, then push them onto stack
    while(front != rear+1) push(dequeue());
    return;
}

void printStack()
{
    if(isSEmpty()){
        printf("The stack is empty.\n");
        return;
    }
    for(int i = top; i >= 0; --i) printf("%d ", stack[i]);
    printf("\n");
    return;
}
