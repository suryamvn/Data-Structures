#include<stdio.h>
// Function to move n discs from p0 to p2 using p1 as an intermediate pole following the rules of the Tower of Hanoi game
void Tower_Of_Hanoi(int n,int p0,int p2,int p1)
// p0, p1, p2 represents the poles which are labelled as 0, 1, 2 respectively
{
    if(n<1)
    {
        return;
    }
    // If there is only one disc(n=1) on p0, then move that disc from p0 to p2 
    if(n==1)
    {
        printf("Move Disk %d from Pole %d to Pole %d\n" , n, p0 , p2);
    }
    else
    {
        // Move the top n-1 discs from p0 to p1 using p2 as an intermediate pole
        Tower_Of_Hanoi(n-1,p0,p1,p2);
        // Move the nth disc from p0 to p2
        printf("Move Disk %d from Pole %d to Pole %d\n" , n , p0 , p2);
        // Move the n-1 discs from p1 to p2 using p0 as an intermediate pole
        Tower_Of_Hanoi(n-1,p1,p2,p0);
        return;
    }
}

int main()
{
    // Declaring the variable n(Number of discs)
    int n;
    // Taking the input of the variable n(Number of discs)
    scanf("%d" , &n);
    // Calling the Tower_Of_Hanoi function
    Tower_Of_Hanoi(n,0,2,1);
    return 0;
}