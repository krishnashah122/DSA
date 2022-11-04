//2. WAP to find out the transpose of a sparse matrix.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int col;
    int val;
    struct node *next;
};

void sparseMatrix(struct node **h, int r, int c, int arr[][c], int count)
{
    *h = (struct node*)malloc(sizeof(struct node));
    (*h)->row = r;
    (*h)->col = c;
    (*h)->val = count;
    struct node *ptr, *curr;
    ptr = *h;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                curr = (struct node*)malloc(sizeof(struct node));
                curr->row = i;
                curr->col = j;
                curr->val = arr[i][j];
                curr->next = NULL;
                ptr->next = curr;
                ptr = curr;
            }
        }
    }
    printf("\n\n");
}

void display(struct node *h)
{
    for (; h != NULL; h = h->next){
        printf("%d %d %d\n", h->row, h->col, h->val);
    }
}

void transpose(struct node *h)
{
    struct node *ptr;
    for (ptr = h; ptr != NULL; ptr = ptr->next)
    {
        int temp = ptr->row;
        ptr->row = ptr->col;
        ptr->col = temp;
    }
}

int main()
{
    struct node *head = NULL;
    int n1, n2, count;
    printf("Enter matrix size: ");
    scanf("%d%d", &n1, &n2);
    int arr[n1][n2];
    printf("Enter elements:\n");
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr[i][j] != 0){
                count++;
            }
        }
    }

    sparseMatrix(&head, n1, n2, arr, count);
    printf("The Triplet Representation:\n");
    display(head);
    transpose(head);
    printf("The Transpose of triplet is\n");
    display(head);

    return 0;
}