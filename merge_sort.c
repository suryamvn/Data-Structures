#include<stdio.h>
// Function to implement top-down merge sort algorithm to sort a list of n integers given in the array A
void merge_sort(int A[],int first,int last)
{
    if(first==last)
    {
        return;
    }
    if(first<last)
    {
        // Declare an array B of size last-first+1
        int B[last-first+1];
        // Declare a variable mid(stores the middle index in the array) and initialize it to (first+last)/2
        int mid=(first+last)/2;
        // Call merge_sort function with actual parameters as A,first,mid
        merge_sort(A,first,mid);
        // Call merge_sort function with actual parameters as A,mid+1,last
        merge_sort(A,mid+1,last);
        // Declare the variables i,j,k and initialize these variables to first,mid+1,0 respectively
        int i=first,j=mid+1,k=0;
        while(i<=mid && j<=last)
        {
            if(A[i]<=A[j]) // If A[i]<=A[j],copy A[i] to B[k]
            {
                B[k]=A[i];
                k++;
                i++;
            }
            else
            {
                B[k]=A[j]; //If A[i]>A[j],copy A[j] to B[k]
                k++;
                j++;
            }
        }
        while(i<=mid)
        {
            B[k]=A[i]; //If i<=mid, then append the remaining elements of A[first,.....,mid] into the array B
            k++;
            i++;
        }
        while(j<=last)
        {
            B[k]=A[j]; //If j<=last, then append the remaining elements of A[mid+1,.....,last] into the array B 
            k++;
            j++;
        }
        int p=first,q=0;
        while(p<=last)
        {
            // Copy the elements of B into A
            A[p]=B[q];
            p++;
            q++;
        }
    }
    
}

int main()
{
    //Declare the variable n
    int n;
    // Ask input of the variable n from the user
    scanf("%d" , &n);
    // Declare an array of size n
    int A[n];
    // Ask input of the elements of the array A
    for(int i=0;i<n;i++)
    {
        scanf("%d" , &A[i]);
    }
    // Call merge_sort function with actual parameters as A,0,n-1
    merge_sort(A,0,n-1);
    // Print the elements of the array A after sorting
    for(int i=0;i<n;i++)
    {
        printf("%d\n" , A[i]);
    }
    return 0;
}