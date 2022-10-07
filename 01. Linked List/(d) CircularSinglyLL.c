#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

//for circular linked list, addAtFirst function do not need to return any pointer
void addAtFirst(struct node *tail, int data)
{
    struct node *head = createNode(data);
    head->next = tail->next;
    tail->next = head;
    return;
}

struct node *addAtLast(struct node *tail, int data)
{
    struct node *temp = createNode(data);
    temp->next = tail->next;
    tail->next = temp;
    return temp;
}

void addAtPosition(struct node *ptr, int data, int position)
{
    struct node *temp = createNode(data);
    while(--position > 1){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return;
}

void deleteFirst(struct node *tail)
{
    struct node *ptr = tail->next;
    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;
    return;
}

struct node *deletePosition(struct node *tail, int position)
{
    struct node *curr = NULL;
    struct node *prev = tail->next;
    while(--position > 1){
        prev = prev->next;
    }
    curr = prev->next;
    prev->next = curr->next;
    if(curr == tail){
        tail = prev;
    }
    free(curr);
    curr = NULL;
    return tail;
}

void searchElement(struct node *tail, int data)
{
    struct node *ptr = tail->next;
    int i = 1;
    if(tail == NULL){
        printf("The linked list is empty.\n");
        return;
    }

    do{
        if(data == ptr->data){
            printf("%d is at position %d.\n", data, i);
            return;
        }
        else{
            ptr = ptr->next;
            ++i;
        }
    } while(ptr != tail->next);

    printf("%d does not exist in the linked list.\n", data);
    return;
}

int countOfNodes(struct node *tail)
{
    struct node *ptr = tail->next;
    int count = 0;
    while(ptr != tail){
        ++count;
        ptr = ptr->next;
    }
    return ++count;
}

void printNodes(struct node *tail)
{
    struct node *ptr = tail->next;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != tail->next);
    return;
}

int main(void)
{
    struct node *tail = NULL;
    int data, position, n;

    printf("Enter the number of nodes = ");
    scanf("%d", &n);

    if(n > 0){
        printf("Enter the node(s) : ");
        scanf("%d", &data);
        tail = createNode(data);
        for(int i = 1; i < n; ++i){
            scanf("%d", &data);
            tail = addAtLast(tail, data);
        }
        printf("\nThe linked list : ");
        printNodes(tail);
        printf("\nTotal nodes = %d\n", countOfNodes(tail));
    }
    else if(n == 0){
        printf("\nNo node in the linked list.\n");
    }

    printf("\nEnter the position where to add a node : ");
    scanf("%d", &position);

    if(position > 0){
        printf("Enter the node : ");
        scanf("%d", &data);

        if(position == 1){
            if(tail == NULL){
                tail = createNode(data);
            }
            else{
                addAtFirst(tail, data);
            }
        }
        else if(position == n+1){
            tail = addAtLast(tail, data);
        }
        else{
            addAtPosition(tail->next, data, position);
        }

        ++n;
        printf("The linked list : ");
        printNodes(tail);
        printf("\n");
    }

    if(n == 0){
        printf("\nThe linked list is empty.\n");
        return 0;
    }

    printf("\nEnter a position for deleting a node : ");
    scanf("%d", &position);

    if(position > 0){
        if(position == 1) deleteFirst(tail);
        else tail = deletePosition(tail, position);

        --n;
        if(n > 0){
            printf("The linked list : ");
            printNodes(tail);
            printf("\n");
        }
        else{
            printf("\nThe linked list is empty.\n");
            return 0;
        }
    }

    printf("\nEnter a element to search : ");
    scanf("%d", &data);
    searchElement(tail, data);
    return 0;
}
