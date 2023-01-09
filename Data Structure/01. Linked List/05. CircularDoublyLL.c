#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}

void addAtFirst(struct node *tail, int data)
{
    struct node *head = createNode(data);
    head->next = tail->next;
    tail->next->prev = head;
    head->prev = tail;
    tail->next = head;
    return;
}

struct node *addAtLast(struct node *tail, int data)
{
    struct node *temp = createNode(data);
    temp->next = tail->next;
    temp->prev = tail;
    tail->next = temp;
    temp->next->prev = temp;
    return temp;
}

void addAtPosition(struct node *ptr, int data, int position)
{
    struct node *temp = createNode(data);
    while(--position > 1) ptr = ptr->next;
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;
    return;
}

void deleteFirst(struct node *tail)
{
    struct node *head = tail->next;
    tail->next = head->next;
    free(head);
    head = NULL;
    tail->next->prev = tail;
    return;
}

struct node *deleteLast(struct node *tail)
{
    struct node *previousTail = tail->prev;
    previousTail->next = tail->next;
    tail->next->prev = previousTail;
    free(tail);
    tail = NULL;
    return previousTail;
}

void deletePosition(struct node *prev, int position)
{
    struct node *curr = NULL;
    while(--position > 1) prev = prev->next;
    curr = prev->next;
    prev->next = curr->next;
    curr->next->prev = prev;
    free(curr);
    curr = NULL;
    return;
}

void printNodes(struct node *tail)
{
    struct node *ptr = tail->next;
    do{
        printf(" %d", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
    return;
}

int main(void)
{
    int data, position, n;
    struct node *tail = NULL;

    printf("Number of nodes = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter your node(s) : ");
        scanf("%d", &data);
        tail = createNode(data);

        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }

        printf("\nThe linked list :");
        printNodes(tail);
        printf("\n");
    }
    else printf("\nThe linked list is empty\n");

    printf("\nEnter a position for inserting a node : ");
    scanf("%d", &position);

    if(position > 0){
        printf("Enter a node at position %d : ", position);
        scanf("%d", &data);

        if(position == 1){
            if(tail == NULL) tail = createNode(data);
            else addAtFirst(tail, data);
        }
        else if(position == n + 1) tail = addAtLast(tail, data);
        else addAtPosition(tail->next, data, position);

        ++n;
        printf("\nThe linked list :");
        printNodes(tail);
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
                free(tail);
                tail = NULL;
            }
            else deleteFirst(tail);
        }
        else if(position == n) tail = deleteLast(tail);
        else deletePosition(tail->next, position);

        --n;
        if(n == 0){
            printf("\nThe linked list is empty\n");
            return 0;
        }
    }

    printf("\nThe linked list :");
    printNodes(tail);
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
