//double ended queue is an extension of circular queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

bool isFull();
bool isEmpty();
void enqueueFront(int);
void enqueueRear(int);
int dequeueFront();
int dequeueRear();
int peek();
void printChoiceList();
void printQueue();

int deque[MAX];
int front = -1;
int rear = -1;

int main(void)
{
    int choice, data;
    while(true){
        printChoiceList();
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                enqueueFront(data);
                printf("Element is inserted successfully.\n");
                break;
            case 2:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                enqueueRear(data);
                printf("Element is inserted successfully.\n");
                break;
            case 3:
                printf("Deleted element is %d\n", dequeueFront());
                break;
            case 4:
                printf("Deleted element is %d\n", dequeueRear());
                break;
            case 5:
                printf("The first element is %d\n", peek());
                break;
            case 6:
                printQueue();
                break;
            case 7:
                printf("Fee Amanillah\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}

bool isFull()
{
    if((front == 0 && rear == MAX-1) || (front == rear+1)){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty()
{
    if(front == -1){
        return true;
    }
    else{
        return false;
    }
}

void enqueueFront(int data)
{
    if(isFull()){
        printf("Queue overflow.\n");
        exit(1);
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else if(front == 0){
        front = MAX-1;
    }
    else{
        --front;
    }
    deque[front] = data;
    return;
}

void enqueueRear(int data)
{
    if(isFull()){
        printf("Queue overflow.\n");
        exit(1);
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else if(rear == MAX-1){
        rear = 0;
    }
    else{
        ++rear;
    }
    deque[rear] = data;
    return;
}

int dequeueFront()
{
    if(isEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }

    int value = deque[front];
    if(front == rear){  //only one element left in the queue
        front = rear = -1;
    }
    else if(front == MAX-1){
        front = 0;
    }
    else{
        ++front;
    }
    return value;
}

int dequeueRear()
{
    if(isEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }

    int value = deque[rear];
    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX-1;
    }
    else{
        --rear;
    }
    return value;
}

int peek()
{
    if(isEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }
    return deque[front];
}

void printChoiceList()
{
    printf("1. Insert at front\n");
    printf("2. Insert at rear\n");
    printf("3. Delete from front\n");
    printf("4. Delete from rear\n");
    printf("5. Print the first element\n");
    printf("6. Print all the elements\n");
    printf("7. Quit\n");
    return;
}

void printQueue()
{
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue : ");
    int i = front;
    while(i != rear){
        printf("%d ", deque[i]);
        if(i == MAX-1){
            i = 0;
        }
        else{
            ++i;
        }
    }
    printf("%d\n", deque[rear]);
    return;
}
