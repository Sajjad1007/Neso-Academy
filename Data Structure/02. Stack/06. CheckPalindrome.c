#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    char data;
    struct node *link;
} *top = NULL;

bool isEmpty()
{
    if(top == NULL) return true;
    else return false;
}

void push(char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Stack overflow\n");
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
    return;
}

char pop()
{
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }

    struct node *ptr = top;
    top = top->link;
    char value = ptr->data;
    free(ptr);
    ptr = NULL;
    return value;
}

bool isPalindrome(char *str)
{
    int i = 0;
    while(str[i] != 'x') push(str[i++]); //pushing characters onto stack until 'x' is found

    while(str[++i]){
        if(isEmpty() || str[i] != pop()) return false;
    }

    if(isEmpty()) return true;
    else return false;
}

int main(void)
{
    char str[100];
    printf("Please enter a string (keeping \'x\' in middle) : ");
    scanf("%s", str);

    if(isPalindrome(str)) printf("\n\"%s\" is a palindrome\n", str);
    else printf("\n\"%s\" is not a palindrome\n", str);
    return 0;
}

/*
Please enter a string (keeping 'x' in middle) : abbcxcbab

"abbcxcbab" is not a palindrome
*/
