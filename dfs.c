#include<stdio.h>
#include<stdlib.h>

struct node // Define structure for node of the linked list
{
    int vertex;
    struct node *next;
};

struct ll // Define structure for the linked list for each element in the array
{
  struct node *head;
  struct node *last;
};

// Function to make vertx and adj_vertx as adjacent vertices
void adjacent(struct ll* arr[],int vertx,int adj_vertx)
{
    // Allocate memory of a node to which temp pointer will point to
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Failed in allocating memory\n");
        return;
    }
    // Store adj_vertex in temp node
    temp->vertex=adj_vertx;
    temp->next=NULL;
    // If there are no adjacent vertices of arr[vertex] till now, then make temp as the head
    if(arr[vertx]->head==NULL)
    {
        arr[vertx]->head=temp;
    }
    else // else make temp as the last 
    {
        arr[vertx]->last->next=temp;
    }
    arr[vertx]->last=temp;
    arr[vertx]->last->next=NULL;
}

// Function to visit the neighbouring nodes from start_vertx
int DFS_Explore(struct ll* arr[],int start_vertx,int entry[],int clk,int EXIT[],int visited[])
{
    // Make start_vertx as visited and change the entry according to the clock
    visited[start_vertx]=1;
    entry[start_vertx]=clk;
    // Increase the clock as one node has been visited
    clk+=1;
    // currptr points to the first neighbour of the start_vertx(according to the input) 
    struct node *currptr;
    currptr=arr[start_vertx]->head;
    // Visit the unvisited neighbouring nodes and if the neighbouring nodes also have unvisited neighbouring nodes, visit them
    while(currptr!=NULL)
    {
        if(visited[currptr->vertex]==0)
        {
            visited[currptr->vertex]=1;
            clk=DFS_Explore(arr,currptr->vertex,entry,clk,EXIT,visited);
        }
        currptr=currptr->next;
    }
    // Change the EXIT according to the clock
    EXIT[start_vertx]=clk;
    // Increase the clock as we have exited the start_vertx
    clk+=1;
    return(clk);
}

// Function to implement explore function for the detached subgraph
int DFS_Explore_detached(struct ll* arr[],int n,int entry[],int clk,int EXIT[],int visited[])
{
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            clk=DFS_Explore(arr,i,entry,clk,EXIT,visited);
        }
    }
    return(clk);
}

int main()
{
    int n,m,start_vertx,clk=0,x,y;
    // Ask input for the number of vertices in the graph
    scanf("%d" , &n);
    // Ask input for the number of edges in the graph
    scanf("%d" , &m);
    // Declare arrays arr,visited,entry,EXIT of size n
    struct ll* arr[n];
    int visited[n];
    int entry[n];
    int EXIT[n];
    // Initilaize the above arrays 
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        entry[i]=-1;
        EXIT[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        // Create a memory for arr[i] to point to
        arr[i]=(struct ll*) malloc(sizeof(struct ll));
        // Make both head and last as NULL
        arr[i]->head=NULL;
        arr[i]->last=arr[i]->head;
    }
    for(int i=0;i<m;i++)
    {
        // Taking inputs for x and y
        scanf("%d %d" , &x,&y);
        //Call adjacent function
        adjacent(arr,x,y);
        adjacent(arr,y,x);
    }
    // Ask input for start_vertx(starting vertex of dfs)
    scanf("%d" , &start_vertx);
    // Call DFS_Explore function
    clk=DFS_Explore(arr,start_vertx,entry,clk,EXIT,visited);
    // Call DFS_Explore_detached function
    clk=DFS_Explore_detached(arr,n,entry,clk,EXIT,visited);
    // Print the values of EXIT and entry for each graph vertex
    for(int i=0;i<n;i++)
    {
        printf("%d %d" , entry[i],EXIT[i]);
        printf("\n");
    }
    return 0;
}