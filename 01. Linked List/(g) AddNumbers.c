#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *addNode(struct node *tail, int val)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->link = NULL;
    if(tail == NULL) return newNode;
    else{
        tail->link = newNode;
        return newNode;
    }
}

struct node *pushNode(struct node *head, int val)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->link = head;
    return newNode;
}

struct node *addNumbers(struct node *ptr1, struct node *ptr2, struct node *head3)
{
    int sum = 0;
    while(ptr1 || ptr2){
        if(ptr1 != NULL){
            sum += ptr1->data;
            ptr1 = ptr1->link;
        }
        if(ptr2){
            sum += ptr2->data;
            ptr2 = ptr2->link;
        }
        head3 = pushNode(head3, sum%10);
        sum /= 10;
    }
    if(sum != 0){
        head3 = pushNode(head3, sum);
    }
    return head3;
}

void printNodes(struct node *ptr)
{
    while(ptr){
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
    return;
}

int main(void)
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    struct node *tail1 = NULL;
    struct node *tail2 = NULL;
    int num1, num2;

    printf("Enter first number = ");
    scanf("%d", &num1);
    tail1 = head1 = addNode(tail1, num1%10);
    num1 /= 10;
    while(num1 != 0){
        tail1 = addNode(tail1, num1%10);
        num1 /= 10;
    }

    printf("Enter second number = ");
    scanf("%d", &num2);
    tail2 = head2 = addNode(tail2, num2%10);
    num2 /= 10;
    while(num2 != 0){
        tail2 = addNode(tail2, num2%10);
        num2 /= 10;
    }

    printf("\nThe reversed first number = ");
    printNodes(head1);
    printf("The reversed second number = ");
    printNodes(head2);
    head3 = addNumbers(head1, head2, head3);
    printf("\nThe sum of two numbers = ");
    printNodes(head3);
    return 0;
}
