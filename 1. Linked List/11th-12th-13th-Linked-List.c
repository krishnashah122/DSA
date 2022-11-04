#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Creating Nodes
void createNode(struct node **h, int n)
{
    struct node *ptr;
    struct node *curr;
    for (int i = 0; i < n; i++)
    {
        curr = malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &curr->data);
        curr->next = NULL;
        if (*h == NULL)
        {
            ptr = *h = curr;
        }
        else
        {
            ptr->next = curr;
            ptr = curr;
        }
    }
}

// Displaying the elements by Traversing the Linked List
void display(struct node *h)
{
    if (h == NULL)
    {
        printf("The Linked List is Empty.");
    }
    else
    {
        while (h != NULL)
        {
            printf("%d ", h->data);
            h = h->next;
        }
        printf("\n");
    }
}

// Inserting node at any given position
void insertNode(struct node **h, int d, int pos)
{
    int i = 1;
    struct node *ptr = *h;
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    curr->data = d;
    curr->next = NULL;
    while (ptr->next != NULL && i < pos - 1)
    {
        ptr = ptr->next;
        i++;
    }
    if (pos == 1)
    {
        curr->next = ptr;
        *h = ptr = curr;
    }
    else
    {
        curr->next = ptr->next;
        ptr->next = curr;
    }
}

// Checking whether the linked list is empty or not
void isEmpty(struct node *h){
    if(h == NULL){
        printf("\nThe Linked List is Empty.\n");
    }else{
        printf("\nThe Linked List is not Empty.\n");
    }
}

// Counting the number of nodes
void counter(struct node *h){
    int count = 0;
    struct node *ptr = h;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("\nThe number of nodes in the Linked List is %d.\n", count);
}

// Searching for a element in the linked list
void search(struct node *h, int x){
    struct node *ptr = h;
    int flag = 0;
    while(ptr != NULL){
        if(ptr->data == x){
            flag = 1;
        }
        ptr = ptr->next;
    }
    if(flag == 1){
        printf("The element %d is found.\n", x);
    }else{
        printf("The element %d is not found.\n", x);
    }
}

void countNthFromLast(struct node *ptr, int x){
    static int k = 0;
    if(ptr == NULL){
        return;
    }
    count (ptr->next, x);
    k++;
    if(k==x){
        printf("%d", ptr->data);
    }
    return;
}

int main()
{
    struct node *head = NULL;
    int n, num, index, a, ln;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    createNode(&head, n);

    printf("\nThe Linked List: ");
    display(head);

    printf("\nWhich element you want to insert? ");
    scanf("%d", &num);
    printf("Where you want to insert the element? ");
    scanf("%d", &index);

    insertNode(&head, num, index);

    printf("\nThe Linked List after inserting element: ");
    display(head);
    
    isEmpty(head);
    counter(head);

    printf("\nWhich element you want to search? ");
    scanf("%d", &a);
    search(head, a);

    printf("Enter position of element that you want from last: ");
    scanf("%d", &ln);
    countNthFromLast(head, ln);

    return 0;
}