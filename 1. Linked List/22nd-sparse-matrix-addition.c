//4. WAP to add two sparse matrix.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int r, c, v;
    struct node *next;
};
void createNode(struct node **h)
{
    struct node *ptr;
    *h = (struct node *)malloc(sizeof(struct node));
    printf("Enter the total no. of row, column and number of non-zero value: ");
    scanf("%d%d%d", &(*h)->r, &(*h)->c, &(*h)->v);
    (*h)->next = NULL;
    ptr = *h;

    for (int i = 0; i < (*h)->v; i++)
    {
        struct node *curr;
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the row, colum and non-zero value: ");
        scanf("%d%d%d", &curr->r, &curr->c, &curr->v);
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
}
void add(struct node *h1, struct node *h2, struct node **h)
{
    if (h1->r != h2->r || h1->c != h2->c){
        return;
    }
    struct node *ptr, *ptr1;
    *h = (struct node *)malloc(sizeof(struct node));
    (*h)->r = h1->r;
    (*h)->c = h1->c;
    (*h)->v = h1->v + h2->v;
    (*h)->next = NULL;
    ptr = *h;
    for (ptr1 = h1->next; ptr1 != NULL; ptr1 = ptr1->next)
    {
        struct node *curr;
        curr = (struct node *)malloc(sizeof(struct node));
        *curr = *ptr1;
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
    for (ptr1 = h2->next; ptr1 != NULL; ptr1 = ptr1->next)
    {
        struct node *curr;
        curr = (struct node *)malloc(sizeof(struct node));
        *curr = *ptr1;
        curr->next = NULL;
        ptr->next = curr;
        ptr = curr;
    }
}
void simplify(struct node **h)
{
    struct node *ptr, *temp, *prev;
    for (ptr = *h; ptr != NULL; ptr = ptr->next)
    {
        prev = ptr;
        temp = ptr->next;
        while (temp != NULL)
        {
            if (ptr->r == temp->r && ptr->c == temp->c)
            {
                ptr->v += temp->v;
                prev->next = temp->next;
                free(temp);
                temp = prev;
                (*h)->v--;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}
void display(struct node *h)

{
    for (; h != NULL; h = h->next){
        printf("%d %d %d\n", h->r, h->c, h->v);
    }
}
int main()
{
    struct node *h, *h1, *h2;
    h = h1 = h2 = NULL;
    createNode(&h1);
    createNode(&h2);
    add(h1, h2, &h);
    simplify(&h);
    display(h);

    return 0;
}