#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

bool isQFull();
bool isQEmpty();
void enqueue(int);
int dequeue();
void push(int);
int pop();
void reverseQueue();
void printQueue();

int queue[MAX];
int stack[MAX];
int front = -1;
int rear = -1;
int top = -1;

int main(void)
{
    int data;
    printf("Enter %d elements in the queue : ", MAX);
    for(int i = 1; i <= MAX; i++){
        scanf("%d", &data);
        enqueue(data);
    }
    reverseQueue();
    printf("After reversing, the queue : ");
    printQueue();
    return 0;
}

bool isQFull()
{
    if(rear == MAX-1) return true;
    else return false;
}

bool isQEmpty()
{
    if(front == -1 || front == rear+1) return true;
    else return false;
}

void enqueue(int data)
{
    if(isQFull()){
        printf("Queue overflow.\n");
        exit(1);
    }
    if(front == -1) front = 0;
    queue[++rear] = data;
    return;
}

int dequeue()
{
    if(isQEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }
    return queue[front++];
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

void reverseQueue()
{
    //dequeue elements from queue, then push them onto stack
    while(!isQEmpty()) push(dequeue());
    front = rear = -1; //reset front and rear
    //pop elements from stack, then enqueue them onto queue
    while(top != -1) enqueue(pop());
    return;
}

void printQueue()
{
    if(isQEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    for(int i = front; i <= rear; ++i) printf("%d ", queue[i]);
    printf("\n");
    return;
}
