#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *link;
} *top = NULL;

struct node *createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

bool isFull()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) return true;
    else return false;
}

bool isEmpty()
{
    if(top == NULL) return true;
    else return false;
}

void push(int data)
{
    if(isFull()){
        printf("Stack overflow.\n");
        exit(1);
    }
    struct node *temp = createNode(data);
    temp->link = top;
    top = temp;
    return;
}

int pop()
{
    if(isEmpty()){
        printf("Stack underflow.\n");
        exit(1);
    }
    struct node *ptr = top;
    top = top->link;
    int value = ptr->data;
    free(ptr);
    ptr = NULL;
    return value;
}

int peek()
{
    if(isEmpty()){
        printf("Stack underflow.\n");
        exit(1);
    }
    return top->data;
}

void printChoiceList()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Print all the elements\n");
    printf("5. Quit\n");
    return;
}

void printStack()
{
    if(isEmpty()){
        printf("The stack is empty.\n");
        return;
    }
    struct node *ptr = top;
    printf("The stack : ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return;
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
                printf("Enter the element to be pushed : ");
                scanf("%d", &data);
                push(data);
                printf("Element is pushed successfully.\n");
                break;
            case 2:
                printf("Deleted element is %d\n", pop());
                break;
            case 3:
                printf("The topmost element is %d\n", peek());
                break;
            case 4:
                printStack();
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
