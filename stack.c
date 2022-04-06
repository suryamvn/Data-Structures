#include <stdio.h>
#include <stdlib.h>
struct node //Define structure for node
{
    int element;
    struct node *next;
};

struct node *top;

void Push() //Function to push the element
{
    struct node *inpptr;
    inpptr = (struct node *)malloc(sizeof(struct node));
    // Ask user for input of the element to be pushed
    scanf("%d" , &(inpptr->element));
    inpptr->next = NULL;
    //if the stack is empty, then point top to this element
    if (top == NULL) 
    {
        top = inpptr;
        return;
    }
    //if the stack is not empty, then push the element
    else if (top != NULL) 
    {
        inpptr->next = top;
        top = inpptr;
        return;
    }
    // if the push operation fails, then print a message
    else 
    {
        printf("Push Failure\n");
    }
}

void IsEmpty() //Function to check whether the stack is empty or not
{
    if (top == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Non Empty\n");
    }
}

void Top() //Function to print the top element
{
    if (top != NULL)
    {
        printf("%d\n", top->element);
    }
    else
    {
        printf("Empty List\n");
    }
}

int Pop() // Function to pop top element
{
    //if Pop operation fails, then print a message saying the same
    if (top == NULL) 
    {
        printf("Pop Failure\n");
    }
    //pop the top elementin the stack
    else  
    {
        struct node *popptr;
        popptr = top;
        top = top->next;
        printf("%d\n", popptr->element);
        //Deallocate the memory which is allocated for popptr
        free(popptr);
    }
}

// Function for printing the elements which are in the stack from top to bottom
void Display()
{
    struct node *displayptr;
    displayptr = top;
    if (top == NULL) //If the stack is empty, print a message saying the same
    {
        printf("Empty List\n");
    }
    else //print the elements which are in the stack from top to bottom
    {
        while (displayptr != NULL)
        {
            printf("%d\n",displayptr->element);
            displayptr = displayptr->next;
        }
    }
}
int main()
{
    int a;
    top = NULL;
    while (1)
    {
        scanf("%d", &a);
        //If a=0, call IsEmpty function
        if (a == 0)
        {
            IsEmpty();
        }
        // If a=1, call Push function
        else if (a == 1)
        {
            Push();
        }
        // If a=2, call Pop function
        else if (a == 2)
        {
            Pop();
        }
        // If a=3,call Top function
        else if (a == 3)
        {
            Top();
        }
        // If a=4, call Display function
        else if (a == 4)
        {
            Display();
        }
        // If a=5, terminate the program
        else if (a == 5)
        {
            return 0;
        }
    }
}