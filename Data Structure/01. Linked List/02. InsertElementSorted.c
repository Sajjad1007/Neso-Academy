#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

struct node *addAtLast(struct node *tail,int data)
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
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return;
}

int main(void)
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int data, n;
    printf("Number of nodes in the list = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter %d node(s) in ascending order : ", n);
        scanf("%d", &data);
        tail = head = createNode(data);
        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }
        printf("The list before insertion : ");
        printNodes(head);
        printf("\n");
    }
    else printf("No nodes in the list.\n");

    printf("\nEnter a node to insert = ");
    scanf("%d", &data);

    if((head == NULL) || (data < head->data)){
        struct node *temp = createNode(data);
        temp->link = head;
        head = temp;
    }
    else insertNode(head, data);

    printf("The list after insertion : ");
    printNodes(head);
    printf("\n");
    return 0;
}
