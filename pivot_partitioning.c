#include<stdio.h>
int main()
{
    // Declaring variables(n,pivot,k,i,j,r) and initializing variable(r)
    int n,pivot,r=0,k,i,j;
    // Taking the input of the variable(n)
    scanf("%d" , &n);
    // Declaring an array of size n
    int A[n];
    // Taking input for the values of the elements in the array
    for(i=0;i<n;i++)
    {
        scanf("%d" , &A[i]);
    }
    // Taking input of the variable(k)
    scanf("%d" , &k);
    // Initializing the variable(pivot)
    pivot=A[k];
    // Counting the number of elements strictly less than the pivot
    for(i=0;i<n;i++)
    {
        if(A[i]<pivot)
        {
            r++;
        }
    }
    // Exchange A[k] with A[r] so that pivot is at index r in the array
    A[k]=A[r];
    A[r]=pivot;
    // Assign the variables i and j with values 0 and r+1 respectively
    i=0,j=r+1;
    while(i<r && j<n)
    {
        while(i<r && A[i]<A[r])  //Finding an element(with index less than r) which is greater than A[r] and storing its index in variable i
        {
            i++;
        }
        while(j<n && A[j]>=A[r])  //Finding an element(with index greater than r and less than n) which is less than A[r] and storing its index in variable j
        {
            j++;
        }
        if(i<r && j<n)  
        {
            //Exchange the above two elements(A[i] and A[j])
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i++;
            j++;
        }
    }
    // Printing the elements of the array after partitioning
    for(i=0;i<n;i++)
    {
        printf("%d\n" , A[i]);
    }
    return 0;
}