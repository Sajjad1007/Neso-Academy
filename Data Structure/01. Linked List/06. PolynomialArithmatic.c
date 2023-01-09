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
    struct node *temp = (struct node *)malloc(sizeof(struct node));
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

    printf("Number of terms = ");
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
            head3 = insertNode(head3, (ptr1->coef) + (ptr2->coef), ptr1->expo);
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

    printf("\n\nAdded polynomial = ");
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
            head3 = insertNode(head3, (ptr1->coef) * (ptr2->coef), (ptr1->expo) + (ptr2->expo));
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
    printf("Creating first polynomial...\n\n");
    head1 = createPolynomial(head1);
    printf("\nThe first polynomial = ");
    printPolynomial(head1);
    printf("\n\nCreating second polynomial...\n\n");
    head2 = createPolynomial(head2);
    printf("\nThe second polynomial = ");
    printPolynomial(head2);
    printAddedPolynomial(head1, head2);
    printMultipliedPolynomial(head1, head2);
    return 0;
}

/*
Creating first polynomial...

Number of terms = 3

Enter the coefficient and exponent for term 1 : 3 2
Enter the coefficient and exponent for term 2 : -5 1
Enter the coefficient and exponent for term 3 : 1 0

The first polynomial = (3x^2) + (-5x^1) + (1x^0)


Creating second polynomial...

Number of terms = 3

Enter the coefficient and exponent for term 1 : -2 2
Enter the coefficient and exponent for term 2 : 3 1
Enter the coefficient and exponent for term 3 : 4 0

The second polynomial = (-2x^2) + (3x^1) + (4x^0)


Added polynomial = (1x^2) + (-2x^1) + (5x^0)
Multiplied polynomial = (-6x^4) + (19x^3) + (-5x^2) + (-17x^1) + (4x^0)
*/
