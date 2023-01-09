#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev; //extra node for backward traversing
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *addAtFirst(struct node *head, int data)
{
    struct node *temp = createNode(data);
    temp->next = head;
    head->prev = temp;
    return temp;
}

struct node *addAtLast(struct node *tail, int data)
{
    struct node *temp = createNode(data);
    tail->next = temp;
    temp->prev = tail;
    return temp;
}

void addAtPosition(struct node *ptr, int data, int position)
{
    struct node *temp = createNode(data);
    --position;

    while(--position) ptr = ptr->next;
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp; //for last position ptr->next == NULL, so we can not add any node at last position with this function
    ptr->next = temp;
    return;
}

struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    head->prev = ptr = NULL;
    return head;
}

struct node *deleteLast(struct node *tail)
{
    struct node *ptr = tail;
    tail = tail->prev;
    free(ptr);
    tail->next = ptr = NULL;
    return tail;
}

void deletePosition(struct node *prev, int position)
{
    struct node *curr = NULL;
    --position;

    while(--position) prev = prev->next;
    curr = prev->next;
    prev->next = curr->next;
    curr->next->prev = prev;
    free(curr);
    curr = NULL;
    return;
}

void printNodes(struct node *ptr)
{
    while(ptr != NULL){
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    return;
}

int main(void)
{
    int data, position, n;
    struct node *head = NULL;
    struct node *tail = NULL;

    printf("Number of nodes = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter your node(s) : ");
        scanf("%d", &data);
        tail = head = createNode(data);

        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }

        printf("\nThe linked list :");
        printNodes(head);
        printf("\n");
    }
    else printf("\nThe linked list is empty\n");

    printf("\nEnter a position for inserting a node : ");
    scanf("%d", &position);

    if(position > 0){
        printf("Enter a node at position %d : ", position);
        scanf("%d", &data);

        if(position == 1){
            if(head == NULL) head = createNode(data);
            else head = addAtFirst(head, data);
        }
        else if(position == n + 1) tail = addAtLast(tail, data);
        else addAtPosition(head, data, position);

        ++n;
        printf("\nThe linked list :");
        printNodes(head);
        printf("\n");
    }

    if(n == 0){
        printf("\nThe linked list is empty\n");
        return 0;
    }

    printf("\nEnter a position for deleting a node : ");
    scanf("%d", &position);

    if(position > 0){
        if(position == 1){
            if(n == 1){
                free(head);
                head = NULL;
            }
            else head = deleteFirst(head);
        }
        else if(position == n) tail = deleteLast(tail);
        else deletePosition(head, position);

        --n;
        if(n == 0){
            printf("\nThe linked list is empty\n");
            return 0;
        }
    }

    printf("\nThe linked list :");
    printNodes(head);
    printf("\n");
    return 0;
}

/*
Number of nodes = 5
Enter your node(s) : 1 2 3 4 5

The linked list : 1 2 3 4 5

Enter a position for inserting a node : 2
Enter a node at position 2 : 0

The linked list : 1 0 2 3 4 5

Enter a position for deleting a node : 6

The linked list : 1 0 2 3 4
*/
