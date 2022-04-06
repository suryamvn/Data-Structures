#include<stdio.h>
/* Function to find the index of the largest element from the array A and 
exchange the element in that position with the element in the last position*/
void Selection_Sort(int n,int A[])
{
    // Declaring and Initializing the variables(max, temp)
    int max=0,temp=0;
    if(n==1)
    {
        return;
    }
    // Storing the index of the largest element among the first n elements of the array A into the variable max
    for(int i=0;i<n;i++)
    {
        if(A[i]>A[max])
        {
            max=i;
        }
    }
    // Exchange the element of index max with the element of index n-1 in the array A
    temp=A[max];
    A[max]=A[n-1];
    A[n-1]=temp;
    // Calling the Selection_Sort function but with actual arguments as n-1 and A 
    Selection_Sort(n-1,A);
}

int main()
{
    // Declare the variable n(Number of elements in the array A)
    int n;
    // Taking input of the variable n
    scanf("%d" , &n);
    // Declaring an array of size n
    int A[n];
    // Taking input of the elements of the array A
    for(int i=0;i<n;i++)
    {
        scanf("%d" , &A[i]);
    }
    // Calling the Selection_Sort function
    Selection_Sort(n,A);
    // Now, the elements in the array A are sorted
    // Print the elements of the array
    for(int i=0;i<n;i++)
    {
        printf("%d\n" , A[i]);
    }
    return 0;
}