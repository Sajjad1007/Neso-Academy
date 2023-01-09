#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

struct node *addAtLast(struct node *tail, int data)
{
    struct node *temp = createNode(data);
    tail->link = temp;
    return temp;
}

void insertNode(struct node *ptr, int data)
{
    struct node *temp = createNode(data);
    while((ptr->link != NULL) && (ptr->link->data < data)) ptr = ptr->link;
    temp->link = ptr->link;
    ptr->link = temp;
    return;
}

void printNodes(struct node *ptr)
{
    while(ptr != NULL){
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
    return;
}

int main(void)
{
    int data, n;
    struct node *head = NULL;
    struct node *tail = NULL;
    printf("Number of nodes = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter %d node(s) in ascending order : ", n);
        scanf("%d", &data);
        tail = head = createNode(data);

        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }

        printf("\nThe linked list before insertion :");
        printNodes(head);
        printf("\n");
    }
    else printf("\nThe linked list is empty\n");

    printf("\nEnter a node to insert : ");
    scanf("%d", &data);

    if((head == NULL) || (data < head->data)){
        struct node *temp = createNode(data);
        temp->link = head;
        head = temp;
    }
    else insertNode(head, data);

    printf("\nThe linked list after  insertion :");
    printNodes(head);
    printf("\n");
    return 0;
}

/*
Number of nodes = 5
Enter 5 node(s) in ascending order : 1 3 4 6 8

The linked list before insertion : 1 3 4 6 8

Enter a node to insert : 5

The linked list after  insertion : 1 3 4 5 6 8
*/
