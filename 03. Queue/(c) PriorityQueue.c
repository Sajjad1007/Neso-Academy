#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty(); //isFull() is not necessary for linked list implementation of queue
void enqueue(int, int);
int dequeue();
void printQueue();

struct node{
    int priority;
    int data;
    struct node *link;
} *front = NULL; //rear pointer will not be needed in case of priority queue

int main(void)
{
    int choice, data, priority;
    while(true){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print all the elements\n");
        printf("4. Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &data);
                printf("Enter element's priority : ");
                scanf("%d", &priority);
                enqueue(priority, data);
                printf("Element is inserted successfully.\n");
                break;
            case 2:
                printf("Deleted element is %d\n", dequeue());
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printf("Fee Amanillah\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}

bool isEmpty()
{
    if(front == NULL){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int priority, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory not available.\n");
        exit(1);
    }
    temp->priority = priority;
    temp->data = data;
    temp->link = NULL;

    if(isEmpty() || (priority < front->priority)){
        temp->link = front;
        front = temp;
    }
    else{
        struct node *ptr = front;
        while((ptr->link != NULL) && (ptr->link->priority <= priority)){
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return;
}

int dequeue()
{
    if(isEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }
    struct node *ptr = front;
    front = front->link;
    int value = ptr->data;
    free(ptr);
    ptr = NULL;
    return value;
}

void printQueue()
{
    if(isEmpty()){
        printf("The queue is empty.\n");
        return;
    }
    struct node *ptr = front;
    printf("The queue : ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return;
}
