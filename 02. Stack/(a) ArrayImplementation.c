#include <stdio.h>
#include <stdlib.h> //for exit(1) function
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1; //the stack is empty

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

void push(int data)
{
    if(isFull()){
        printf("Stack overflow\n");
        exit(1); //exit(1) means abnormal termination of the program
    }
    stack[++top] = data;
    return;
}

int pop()
{
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int peek()
{
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top];
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
        printf("The stack is empty\n");
        return;
    }
    printf("The stack : ");
    for(int i = top; i >= 0; --i) printf("%d ", stack[i]);
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
