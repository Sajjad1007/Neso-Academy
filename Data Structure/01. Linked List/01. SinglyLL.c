#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *createNode(int data)
{
    /*
    if we don't allocate memory for the pointer and try to assign data, it will be an uninitialized or wild pointer
    using malloc() function, we can allocate space in heap memory
    */
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

struct node *addAtFirst(struct node *head, int data)
{
    struct node *temp = createNode(data);
    temp->link = head;
    return temp;
}

struct node *addAtLast(struct node *tail, int data)
{
    struct node *temp = createNode(data);
    tail->link = temp;
    return temp;
}

//function to add nodes at any position(without at beginning)
void addAtPosition(struct node *ptr, int data, int position)
{
    struct node *temp = createNode(data);
    --position;

    while(--position) ptr = ptr->link; //we want ptr to point the (position - 1)th node
    temp->link = ptr->link;
    ptr->link = temp;
    return;
}

struct node *deleteFirst(struct node *head)
{
    struct node *ptr = head;
    head = head->link;
    free(ptr); //ptr is now a dangling pointer
    ptr = NULL;
    return head;
}

struct node *deleteLast(struct node *ptr) //we don't need to return the head pointer
{
    while(ptr->link->link != NULL) ptr = ptr->link; //we want to stop at second last node
    struct node *last = ptr->link;
    free(last);
    ptr->link = last = NULL;
    return ptr;
}

void deletePosition(struct node *prev, int position)
{
    struct node *curr = NULL; //curr will point to the node that we want to delete
    --position; //prev will point to the node before curr

    while(--position) prev = prev->link;
    curr = prev->link;
    prev->link = curr->link;
    free(curr);
    curr = NULL;
    return;
}

/*
function to delete any node with most efficient manner
but it can't delete the last node of a list
*/
void deletePosition2(struct node *toDelete)
//toDelete points to the node we want to delete
{
    struct node *ptr = toDelete->link;
    toDelete->data = ptr->data; //we are actually deleting the node after toDelete
    toDelete->link = ptr->link;
    free(ptr);
    ptr = NULL;
    return;
}

void deleteAllNodes(struct node **head)
{
    while(*head != NULL) *head = deleteFirst(*head);
    //we can't use deleteLast() function here because deleteLast() function cannot remove the first node
    return;
}

struct node *reverse(struct node *ptr)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    /*
    1.first we will edit the "next" to point the node after "ptr"
    2.then we will edit the "ptr->link" to point the node before "ptr"
    3.then we will edit the "prev" to point the node pointed by "ptr"
    4.finally, we will edit "ptr" to point the node pointed by "next"
    */
    while(ptr != NULL){
        next = ptr->link; //for 1st iteration, next is pointing to 2nd node
        ptr->link = prev; //link part of the 1st node is pointing to prev
        prev = ptr; //prev is pointing to 1st node
        ptr = next; //head is pointing to 2nd node
    }
    return prev;
}

int countOfNodes(struct node *ptr)
{
    int count = 0;
    while(ptr != NULL){
        ++count;
        ptr = ptr->link;
    }
    return count;
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
    int n, data, count, position;
    struct node *head = NULL;
    struct node *tail = NULL;

    printf("Number of nodes = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter the node(s) : ");
        scanf("%d", &data);
        tail = head = createNode(data); //creating the first node

        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }

        printf("\nThe linked list :");
        printNodes(head);
        count = countOfNodes(head);
        printf("\nTotal node(s) = %d\n",count);
    }
    else{
        printf("\nThe linked list is empty");
        printf("\nTotal node(s) = %d\n", n);
    }

    printf("\nEnter a position for inserting a node : ");
    scanf("%d", &position);

    if(position > 0){
        printf("Enter a node at position %d : ", position);
        scanf("%d", &data);

        if(position == 1) head = addAtFirst(head, data);
        else if(position == count + 1) tail = addAtLast(tail, data);
        else addAtPosition(head, data, position);

        printf("\nThe linked list :");
        printNodes(head);
        printf("\nTotal node(s) = %d\n", ++n);
    }

    printf("\nEnter a position for deleting a node : ");
    scanf("%d", &position);

    if(position > 0){
        if(position == 1) head = deleteFirst(head);
        else if(position == n) tail = deleteLast(head);
        else deletePosition(head, position);

        --n;
        if(n > 0){
            printf("\nThe linked list :");
            printNodes(head);
            printf("\nTotal node(s) = %d\n", n);
        }
        else{
            printf("\nThe linked list is empty\n");
            printf("So reverse of the linked list does not exist\n");
            return 0;
        }
    }

    head = reverse(head);
    printf("\nThe reversed linked list :");
    printNodes(head);

    deleteAllNodes(&head);
    printf("\n\nThe linked list has been deleted successfully\n");
    return 0;
}

/*
Number of nodes = 5
Enter the node(s) : 1 2 3 4 5

The linked list : 1 2 3 4 5
Total node(s) = 5

Enter a position for inserting a node : 2
Enter a node at position 2 : 0

The linked list : 1 0 2 3 4 5
Total node(s) = 6

Enter a position for deleting a node : 6

The linked list : 1 0 2 3 4
Total node(s) = 5

The reversed linked list : 4 3 2 0 1

The linked list has been deleted successfully
*/
