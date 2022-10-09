#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int coef;
    int expo;
    struct node *link;
};

//function for inserting a term in descending order based on its exponent
struct node *insertNode(struct node *head, int coef, int expo)
{
    struct node *ptr = head;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->expo = expo;
    temp->link = NULL;

    if((head == NULL) || (expo > head->expo)){
        temp->link = head;
        head = temp;
    }
    else{
        while((ptr->link != NULL) && (ptr->link->expo >= expo)) ptr = ptr->link;
        if(ptr->expo == expo) ptr->coef = ptr->coef + coef;
        else{
            temp->link = ptr->link;
            ptr->link = temp;
        }
    }
    return head;
}

//function for creating a polynomial
struct node *createPolynomial(struct node *head)
{
    int n, i;
    int coef, expo;

    printf("Enter the number of terms = ");
    scanf("%d", &n);

    if(n > 0){
        printf("\n");
        for(i = 1; i <= n; ++i){
            printf("Enter the coefficient and exponent for term %d : ", i);
            scanf("%d %d", &coef, &expo); //taking input of a term
            head = insertNode(head, coef, expo); //inserting term onto the linked list
        }
    }
    return head;
}

void printPolynomial(struct node *ptr)
{
    if(ptr == NULL) printf("0\n");
    else{
        while(true){
            printf("(%dx^%d)", ptr->coef, ptr->expo);
            ptr = ptr->link;
            if(ptr != NULL) printf(" + ");
            else{
                printf("\n");
                break;
            }
        }
    }
    return;
}

//function for adding the polynomials and print them
void printAddedPolynomial(struct node *ptr1, struct node *ptr2)
{
    struct node *head3 = NULL;

    while((ptr1 != NULL) && (ptr2 != NULL)){
        if(ptr1->expo == ptr2->expo){
            head3 = insertNode(head3, (ptr1->coef)+(ptr2->coef), ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo){
            head3 = insertNode(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else{
            head3 = insertNode(head3, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }

    while(ptr1 != NULL){
        head3 = insertNode(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        head3 = insertNode(head3, ptr2->coef, ptr2->expo);
        ptr2 = ptr2->link;
    }

    printf("\nAdded polynomial = ");
    printPolynomial(head3);
}

//function for multiplying the polynomials and print them
void printMultipliedPolynomial(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    //check if any of the polynomials is zero
    if(ptr1 == NULL || ptr2 == NULL){
        printf("Multiplied polynomial = 0\n");
        return;
    }

    while(ptr1 != NULL){
        while(ptr2 != NULL){
            head3 = insertNode(head3, (ptr1->coef)*(ptr2->coef), (ptr1->expo)+(ptr2->expo));
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    printf("Multiplied polynomial = ");
    printPolynomial(head3);
    return;
}

int main(void)
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Creating first polynomial...\n");
    head1 = createPolynomial(head1);
    printf("\nThe first polynomial = ");
    printPolynomial(head1);
    printf("\nCreating second polynomial...\n");
    head2 = createPolynomial(head2);
    printf("\nThe second polynomial = ");
    printPolynomial(head2);
    printAddedPolynomial(head1, head2);
    printMultipliedPolynomial(head1, head2);
    return 0;
}
