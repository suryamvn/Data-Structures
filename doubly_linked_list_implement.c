#include<stdio.h>
#include<stdlib.h>

struct node // Define structure for node
{
    int element;
    struct node *next;
    struct node *prev;
};

int main()
{
    int n;
    scanf("%d" , &n);
    // currptr points to the current node, first pointer points to the first node, back pointer points to the back node
    struct node *currptr,*first,*back,*tempptr;
    // Allocate memory for the first node
    currptr=(struct node *) malloc(sizeof(struct node));
    // Ask user for the element in the first node
    scanf("%d" , &(currptr->element));
    first=currptr;
    first->prev=NULL;
    tempptr=first;
    // Allocate memory for the remaining n-1 nodes and ask the user for the input of the element in the corresponding nodes
    for(int i=0;i<n-1;i++)
    {
        currptr->next=(struct node *) malloc(sizeof(struct node));
        currptr=currptr->next;
        scanf("%d" , &(currptr->element));
        back=currptr;
        back->prev=tempptr;
        tempptr=currptr;
    }
    currptr->next=NULL;
    currptr=first;
    // Print all the elements in the linked list in order given by the user
    while(currptr!=NULL)
    {
        printf("%d\n" , currptr->element);
        currptr=currptr->next;
    }
    // Print all the elements of the linked list in the reverse order
    currptr=back;
    while(currptr!=NULL)
    {
        printf("%d\n" , currptr->element);
        currptr=currptr->prev;
    }
    // Remove the first element in the linked list
    tempptr=first;
    first=first->next;
    free(tempptr);
    first->prev=NULL;
    // Remove the back element in the linked list
    tempptr=back;
    back=back->prev;
    free(tempptr);
    back->next=NULL;
    currptr=first;
    // Print all the elements of the linked list in order given by user after removing the first and back elements of the linked list
    while(currptr!=NULL)
    {
        printf("%d\n" , currptr->element);
        currptr=currptr->next;
    }
    currptr=back;
    // Print all the elements of the linked list in reverse order after removing the first and back elements of the linked list
    while(currptr!=NULL)
    {
        printf("%d\n" , currptr->element);
        currptr=currptr->prev;
    }
    return 0;
}