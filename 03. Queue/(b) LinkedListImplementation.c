#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isFull();
bool isEmpty();
void enqueue(int);
int dequeue();
int peek();
void printChoiceList();
void printQueue();

struct node{
    int data;
    struct node *link;
} *front = NULL, *rear = NULL;

struct node *createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

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
                enqueue(data);
                printf("Element is inserted successfully.\n");
                break;
            case 2:
                printf("Deleted element is %d\n", dequeue());
                break;
            case 3:
                printf("The first element is %d\n", peek());
                break;
            case 4:
                printQueue();
                break;
            case 5:
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
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) return true;
    else{
        free(temp);
        return false;
    }
}

bool isEmpty()
{
    if(front == NULL) return true;
    else return false;
}

void enqueue(int data)
{
    if(isFull()){
        printf("Queue overflow.\n");
        exit(1);
    }
    struct node *temp = createNode(data);
    if(isEmpty()) front = rear = temp;
    else{
        rear->link = temp;
        rear = temp;
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

int peek()
{
    if(isEmpty()){
        printf("Queue underflow.\n");
        exit(1);
    }
    return front->data;
}

void printChoiceList()
{
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Print the first element\n");
    printf("4. Print all the elements\n");
    printf("5. Quit\n");
    return;
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
