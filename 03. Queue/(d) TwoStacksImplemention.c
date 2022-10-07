#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

void enqueue(int);
int dequeue();
int peek();
void printQueue();
void push1(int);
void push2(int);
int pop1();
int pop2();

int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

int main(void)
{
    int choice, data;
    while(true){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print the first element\n");
        printf("4. Print all the elements\n");
        printf("5. Quit\n");
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

void enqueue(int data)
{
    if((top1+top2) == MAX-2){
        printf("Queue overflow.\n");
        exit(1);
    }
    push1(data);
    return;
}

int dequeue()
{
    if(top2 == -1){
        if(top1 == -1){
            printf("Queue underflow.\n");
            exit(1);
        }
        while(top1 != -1) push2(pop1());
    }
    return pop2();
}

int peek()
{
    if(top2 == -1){
        if(top1 == -1){
            printf("Queue underflow.\n");
            exit(1);
        }
        else return stack1[0];
    }
    else return stack2[top2];
}

void printQueue()
{
    if(top1 == -1 && top2 == -1){
        printf("The queue is empty.\n");
        return;
    }

    for(int i = top2; i >= 0; --i){
        printf("%d ", stack2[i]);
    }
    for(int i = 0; i <= top1; ++i){
        printf("%d ", stack1[i]);
    }
    printf("\n");
    return;
}

void push1(int data)
{
    stack1[++top1] = data;
    return;
}

void push2(int data)
{
    stack2[++top2] = data;
    return;
}

int pop1()
{
    return stack1[top1--];
}

int pop2()
{
    return stack2[top2--];
}
