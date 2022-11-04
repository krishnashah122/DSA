#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int var1Exp;
    int var2Exp;
    struct node *next;
};

//Creating Polynomial Linked List
void createNode(struct node **h){
    int n;
    struct node *curr, *ptr;
    printf("Enter the no. of terms: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        curr = (struct node*)malloc(sizeof(struct node));
        printf("Enter coefficent, X and Y power respectively: ");
        scanf("%d%d%d", &curr->coef, &curr->var1Exp, &curr->var2Exp);
        curr->next = NULL;
        if(*h == NULL){
            *h = ptr = curr;
        }else{
            ptr->next = curr;
            ptr = curr;
        }
    }
}

//Displaying Polynomial
void display(struct node *h){
    for(; h != NULL; h = h->next){
        if(h->next != NULL){
            printf("%dx^%dy^%d + ", h->coef, h->var1Exp, h->var2Exp);
        }else{
            printf("%dx^%dy^%d = 0\n", h->coef, h->var1Exp, h->var2Exp);
        }
    }
}

int main(){
    struct node *head1;
    head1 = NULL;
    printf("Enter first polynomial:\n");
    createNode(&head1);
    display(head1);
}