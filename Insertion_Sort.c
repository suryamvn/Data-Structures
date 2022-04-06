#include<stdio.h>

/* Function for inserting the A[i] into its appropriate position so that the all the elements in the array 
with indices less than or equal to i are now in non-decreasing order of the corresponding elements in A*/
void Insert(int A[],int i)
{
    // Declaring and Initializing the variable last_element
    int last_element=A[i];
    // Assign the value of n-2 to the variable i
    i--;
    // Shift the elements larger than the last_element by one position
    while(i>=0 && A[i]>last_element)
    {
        A[i+1]=A[i];
        i--;
    }
    // Assign the value stored in the variable last_element to A[i+1]
    A[i+1]=last_element;
}

// Function for implementing Insertion Sort
void Insertion_Sort(int A[],int n)
{
    if(n==1)
    {
        return;
    }
    // Call the Insertion_Sort function with actual parameters as A and n-1
    Insertion_Sort(A,n-1);
    // Call the Insert function with actual parameters as A and n-1
    Insert(A,n-1);
}

int main()
{
    // Declaring the variable n
    int n;
    // Take input of the variable n
    scanf("%d" , &n);
    // Declaring an array of size n
    int A[n];
    // Declaring and Initialzing the variable j
    int j=0;
    // Take input of the elements in the array A
    for(j=0;j<n;j++)
    {
        scanf("%d" , &A[j]);
    }
    // Call the Insertion_Sort function with actual parameters as A and n
    Insertion_Sort(A,n);
    // Print all the elements in the array after sorting
    for(j=0;j<n;j++)
    {
        printf("%d\n" , A[j]);
    }
    return 0;
}