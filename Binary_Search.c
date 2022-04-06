#include<stdio.h>
// Function for returning the index position in the array, where the item can be found. If the item is not present in the array, then the function returns -1
int binary_search(int arr[],int left,int right,int item,int *d)
{
    (*d)++;
    int mid;
    /*If there is only one element need to be checked, and if that element is equal to item, then return the index(left), 
    but if that element is not equal to item, then return -1*/
    if(left==right)
    {
        if(arr[left]==item)
        {
            return(left);
        }
        else 
        {
            return(-1);
        }
    }
    else
    {
        mid=(left+right)/2; //Finding the middle index in the array
        if(arr[mid]==item)  //If the element with the middle index is equal to item, then return index(mid)
        {
            return(mid);
        }
        /*If the value of the item is less than the middle element and middle index is greater than left index, 
        then call the function(binary_search) again but this time with its right index equal to mid-1*/
        else if(arr[mid]>item && mid>left) 
        {
            return(binary_search(arr,left,mid-1,item,d));
            
        }
        /*If the value of the item is greater than the middle element and middle index is lesser than right index, 
        then call the function(binary_search) again but this time with its left index equal to mid+1*/
        else if(arr[mid]<item && mid<right)
        {
            return(binary_search(arr,mid+1,right,item,d));
        }
        // If the above conditions doesn't satisfy, then return -1
        else
        {
            return(-1);
        }
    }
}

int main()
{
    // Declaring variables(n,item,res)
    int n,item,res;
    // Taking input for the value of the variable n(number of elements required)
    scanf("%d" , &n);
    // Declaring an array of size n
    int arr[n];
    // Taking input for the values of the elements in the array
    for(int i=0;i<n;i++)
    {
        scanf("%d" , &arr[i]);
    }
    // Declaring and Initializing variables(left,right,d)
    int left=0,right=n-1,d=0;
    // Taking input for the value of the variable item
    scanf("%d" , &item);
    /* If item is present in the array, then the index position in the array, where the item was found will be stored in the variable(res).
    If the item is not present in the array, then -1 will be stored in the variable(res)*/ 
    res=binary_search(arr,left,right,item,&d);
    // Printing the recursion depth
    printf("%d\n" , d);
    // Printing the value stored in the variable(res)
    printf("%d" , res);
    return 0;
}