#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct ll
{
  struct node *head;
  struct node *last;
};

void adjacent(struct ll* arr[],int vertx,int adj_vertx)
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    temp->vertex=adj_vertx;
    temp->next=NULL;
    if(arr[vertx]->head==NULL)
    {
        arr[vertx]->head=temp;
    }
    else
    {
        arr[vertx]->last->next=temp;
    }
    arr[vertx]->last=temp;
    arr[vertx]->last->next=NULL;
    
}

int main()
{
    int n,x,y;
    scanf("%d" , &n);
    struct ll* arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=(struct ll*) malloc(sizeof(struct ll));
        arr[i]->head=NULL;
        arr[i]->last=arr[i]->head;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d" , &x);
        scanf("%d" , &y);
        adjacent(arr,x,y);
        adjacent(arr,y,x);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]->head==NULL)
        {
            printf("Nil\n");
        }
        else
        {
            while(arr[i]->head!=NULL)
            {
                printf("%d " , arr[i]->head->vertex);
                arr[i]->head=arr[i]->head->next;
            }
            printf("\n");
        }
    }
    return 0;
}