#include<stdio.h>
#include<stdlib.h>

struct node // Define structure for node
{
  int element;
  struct node *next;
};

void IsEmpty(struct node **top,struct node **back) // Function to check if the queue is empty or not
{
    if((*top)==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Non Empty\n");
    }
}

int Enqueue(struct node **top,struct node **back,int error_code,int x) // Function which adds an integer x into the queue
{
    struct node *inpptr;
    // Allocating memory for a node
    inpptr=(struct node *) malloc(sizeof(struct node));
    if(inpptr==NULL) // If the alloaction of memeory for the node fails, return error_code
    {
        (error_code)=-1;
        return(error_code);
    }
    inpptr->element=x;
    inpptr->next=NULL;
    // If the queue is empty, then add the element as the top element
    if((*top)==NULL)
    {
        *back=inpptr;
        *top=(*back);
        return(1);
    }
    // If the queue is non-empty, then place the node pointed by tempptr to the next of the back node in the list
    else
    {
        (*back)->next=inpptr;
        *back=(*back)->next;
        return(1);
    }
}

int Dequeue(struct node **top,struct node **back,int error_code) // Function to remove the top element of the list
{
    if((*top)!=NULL) // If the queue is non-empty, then remove the top element in the queue
    {
        struct node *tempptr;
        tempptr=(*top);
        *top=(*top)->next;
        printf("%d\n" , tempptr->element);
        free(tempptr);
        return(1);
    }
    else // If the queue is empty, then return error_code
    {
        (error_code)=-1;
        return(error_code);
    }
}

int Peek(struct node **top,struct node **back,int error_code) // Function to print the top element in the queue
{
    if((*top)==NULL) // If the queue is empty, then return error_code
    {
        (error_code)=-1;
        return(error_code);
    }
    else // If the queue is non-empty, then print the top element in the queue
    {
        printf("%d\n" , (*top)->element);
        return(1);
    }
}

int Display(struct node **top,struct node **back,int error_code) // Function to display the elements in the queue from front to back
{
    if((*top)==NULL) // If the queue is empty, then print a message saying the same
    {
        printf("Empty List");
        return(1);
    }
    else if((*top)!=NULL) // If the queue is non-empty, then print the elements in the queue from front to back 
    {
        struct node *displayptr;
        displayptr=(*top);
        while(displayptr!=NULL)
        {
            printf("%d\n" , (displayptr)->element);
            displayptr=(displayptr)->next;
        }
        return(1);
    }
    else // If the Display function fails, then return error_code
    {
        (error_code)=-1;
        return(error_code);
    }
}

int main()
{
    int a=0,error_code=0;
    // top pointer points to the top element in the queue
    struct node *top;
    // back pointer points to the back element in the queue
    struct node *back;
    top=NULL;
    back=top;
    while(1)
    {
        scanf("%d" , &a);
        if(a==0) // If a=0, call IsEmpty function
        {
            IsEmpty(&top,&back);
        }
        else if(a==1) // If a=1, call Enqueue function
        {
            int x;
            scanf("%d" , &x);
            error_code=Enqueue(&top,&back,error_code,x);
            if(error_code==-1)
            {
                printf("Enqueue Failure");
            }
        }
        else if(a==2) // If a=2, call Dequeue function
        {
            error_code=Dequeue(&top,&back,error_code);
            if(error_code==-1)
            {
                printf("Dequeue Failure\n");
            }
        }
        else if(a==3) // If a=3, call Peek function
        {
            error_code=Peek(&top,&back,error_code);
            if(error_code==-1)
            {
                 printf("Peek Failure");
            }
        }
        else if(a==4) // If a=4, call Display function
        {
            error_code=Display(&top,&back,error_code);
            if(error_code==-1)
            {
                printf("Display Failure\n");
            }
        }
        else if(a==5) // If a=5, terminate the program successfully
        {
            return 0;
        }
        else // else return -1
        {
            return -1;
        }
    }
}