#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int exp;
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
        printf("Enter coefficent and power respectively: ");
        scanf("%d%d", &curr->coef, &curr->exp);
        curr->next = NULL;
        if(*h == NULL){
            *h = ptr = curr;
        }else{
            ptr->next = curr;
            ptr = curr;
        }
    }
}

//Multiplying Polynomial
void multiplyPolynomial(struct node *h1, struct node *h2, struct node **h){
    struct node *ptr1, *ptr2, *ptr, *curr;
    for(ptr1 = h1; ptr1 != NULL; ptr1 = ptr1->next){
        for(ptr2 = h2; ptr2 != NULL; ptr2 = ptr2->next){
            curr = (struct node*)malloc(sizeof(struct node));
            curr->coef = ptr1->coef * ptr2->coef;
            curr->exp = ptr1->exp + ptr2->exp;
            curr->next = NULL;
            if(*h == NULL){
                *h = ptr = curr;
            }else{
                ptr->next = curr;
                ptr = curr;
            }
        }
    }
}

//Simplifying Polynomial
void simplify(struct node **h){
    struct node *ptr, *prev, *temp;
    for(ptr = *h; ptr != NULL; ptr = ptr->next){
        prev = ptr;
        temp = ptr->next;
        while(temp != NULL){
            if(ptr->exp == temp->exp){
                ptr->coef += temp->coef;
                prev->next = temp->next;
                free(temp);
                temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

//Displaying Polynomial
void display(struct node *h){
    for(; h != NULL; h = h->next){
        if(h->next != NULL){
            printf("%dx^%d + ", h->coef, h->exp);
        }else{
            printf("%dx^%d = 0\n", h->coef, h->exp);
        }
    }
}

int main(){
    struct node *head, *head1, *head2;
    head = head1 = head2 = NULL;
    printf("Enter first polynomial:\n");
    createNode(&head1);
    printf("Enter second polynomial:\n");
    createNode(&head2);
    multiplyPolynomial(head1, head2, &head);
    simplify(&head);
    printf("Polynomial after multiplication:\n");
    display(head);
    return 0;
}