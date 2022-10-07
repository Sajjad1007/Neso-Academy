#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *link;
};

bool isEmpty(struct node **top)
{
    if(*top == NULL) return true;
    else return false;
}

void push(struct node **top, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Stack overflow\n");
        exit(1);
    }
    temp->data = data;
    temp->link = *top;
    *top = temp;
    return;
}

int pop(struct node **top)
{
    if(isEmpty(top)){
        printf("Stack underflow\n");
        exit(1);
    }
    struct node *ptr = *top;
    *top = (*top)->link;
    int value = ptr->data;
    free(ptr);
    ptr = NULL;
    return value;
}

void reverseStack(struct node **top)
{
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    //pushing onto temporary stack 1
    while(!isEmpty(top)){
        push(&top1, pop(top));
    }
    //pushing onto temporary stack 2
    while(!isEmpty(&top1)){
        push(&top2, pop(&top1));
    }
    //pushing onto original stack
    while(!isEmpty(&top2)){
        push(top, pop(&top2));
    }
    return;
}

void printStack(struct node *ptr)
{
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return;
}

int main(void)
{
    struct node *top = NULL;
    int n, data;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    if(n <= 0){
        printf("The stack is empty\n");
        return 0;
    }

    printf("Enter the elements : ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &data);
        push(&top, data);
    }

    printf("\nBefore reversing, the stack : ");
    printStack(top);
    reverseStack(&top);
    printf("After reversing, the stack : ");
    printStack(top);
    return 0;
}
