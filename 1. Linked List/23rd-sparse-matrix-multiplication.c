//Sparse Matrix Multiplication

#include <stdio.h>
#include <stdlib.h>

struct node{
    int row;
    int col;
    int val;
    struct node *next;
};

//Creating Sparse Matrix Linked List
//(Some errors in this function)
void createNode(struct node **h){
    int r, c, n;
    struct node *curr, *ptr;
    printf("Enter the matrix size: ");
    scanf("%d%d", &r, &c);
    printf("Enter the no. of non-zero elements: ");
    scanf("%d", &n);
    (*h) = (struct node*)malloc(sizeof(struct node));
    (*h)->row = r;
    (*h)->col = c;
    (*h)->val = n;
    (*h)->next = NULL;
    ptr = *h;
    for(int i = 0; i < n; i++){
        curr = (struct node*)malloc(sizeof(struct node));
        printf("Enter row, column and value respectively: ");
        scanf("%d%d%d", &curr->row, &curr->col, &curr->val);
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
}

//Multiplying Sparse Matrix
void multiplySparseMatrix(struct node *h1, struct node *h2, struct node **h){
    if(h1->col != h2->row){
        printf("Multiplication not possible.\n");
        return;
    }
    struct node *ptr1, *ptr2, *ptr, *curr;
    (*h) = (struct node*)malloc(sizeof(struct node));
    (*h)->row = h1->row;
    (*h)->col = h2->col;
    (*h)->val = 0;
    (*h)->next = NULL;
    ptr = *h;
    for(ptr1 = h1->next; ptr1 != NULL; ptr1 = ptr1->next){
        for(ptr2 = h2->next; ptr2 != NULL; ptr2 = ptr2->next){
            if(ptr1->col == ptr2->row){
                curr = (struct node*)malloc(sizeof(struct node));
                curr->row = ptr1->row;
                curr->col = ptr2->col;
                curr->val = ptr1->val * ptr2->val;
                curr->next = NULL;
                ptr->next = curr;
                ptr = curr;
                (*h)->val++;
            }
        }
    }
}

//Simplifying
void simplify(struct node **h){
    struct node *ptr, *prev, *temp;
    for(ptr = *h; ptr != NULL; ptr = ptr->next){
        prev = ptr;
        temp = ptr->next;
        while(temp != NULL){
            if(ptr->row == temp->row && ptr->col == temp->col){
                ptr->val += temp->val;
                prev->next = temp->next;
                free(temp);
                temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

//Displaying
void display(struct node *h){
    for(; h != NULL; h = h->next){
        printf("%d %d %d\n", h->row, h->col, h->val);
    }
}

int main(){
    struct node *head1, *head2, *head;
    head = head1 = head2 = NULL;
    printf("Enter first sparse matrix:\n");
    createNode(&head1);
    printf("\nEnter second sparse matrix:\n");
    createNode(&head2);
    multiplySparseMatrix(head1, head2, &head);
    simplify(&head1);
    printf("\nSparse Matrix after multiplication:\n");
    display(head);
    
    return 0;
}