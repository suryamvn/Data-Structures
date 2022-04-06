#include<stdio.h>
#include<stdlib.h>

struct node //Define structure for node
{
    int element;
    struct node *left;
    struct node *right;
    struct node *parent;
};

// Function to insert an element in its appropriate position
struct node* insert(struct node *root,int x)
{
    // If root is null, then allocate memory for a new node where newptr will be pointing to this node
    if(root==NULL)
    {
        struct node *newptr;
        newptr=(struct node *)malloc(sizeof(struct node));
        if(newptr==NULL)
        {
            printf("Insert Fail\n");
            exit(1);
        }
        newptr->element=x;
        newptr->left=NULL;
        newptr->right=NULL;
        newptr->parent=NULL;
        return(newptr);
    }
    // If element to be inserted is less than or equal to element present in the root node, then insert x in the appropriate position to the left of the root node and link them properly
    else if(x<=(root->element))
    {
        struct node *insertptr;
        insertptr=insert(root->left,x);
        insertptr->parent=(root);
        (root)->left=insertptr;
        return(root);
    }
    // If the element to be inserted is greater than element present in the root node, then insert x in the appropriate position to the right of root node and link them properly
    else
    {
        struct node *insertptr1;
        insertptr1=insert((root->right),x);
        insertptr1->parent=(root);
        (root)->right=insertptr1;
        return(root);
    }
}

// Function to implement search of the element x in the binary search tree
struct node* search(struct node **root, int x)
{
    // If root is NULL, return NULL
    if(*root == NULL)
    {
        struct node *temp=NULL;
        return(temp);
    }
    else
    {
        // If x is equal to element in root node, return root
        if(x== (*root)->element)
        {
            return(*root);
        }
        // If x is less than root element, then search in left of root node
        else if(x< (*root)->element)
        {
            search(&((*root)->left),x);
        }
        // If x is greater than root element, then search in right of root node
        else
        {
            search(&((*root)->right),x);
        }
    }
}

// Function to print the elements through inorder traversal
void inorder(struct node **root)
{
    if((*root)==NULL)
    {
        return;
    }
    else
    {
        inorder(&((*root) -> left));
        printf("%d\n" , (*root) -> element);
        inorder(&((*root) -> right));
    }
}
// Function to print the elements through preorder traversal
void preorder(struct node **root)
{
    if((*root)==NULL)
    {
        return;
    }
    else
    {
        printf("%d\n" , (*root) -> element);
        preorder(&((*root) -> left));
        preorder(&((*root) -> right));
    }
}
// Function to print the elements in postorder traversal
void postorder(struct node **root)
{
    if((*root)==NULL)
    {
        return;
    }
    else
    {
        postorder(&((*root) -> left));
        postorder(&((*root) -> right));
        printf("%d\n" , (*root) -> element);
    }
}

// Function to find the predecessor of the element of the node which elem pointer is pointing to
int predecessor(struct node **elem,struct node **root)
{
    struct node *currptr;
    if((*elem)==NULL) // If elem pointer is NULL, then print an error message in the main function
    {
        return(-1);
    }
    else if((*elem)->left != NULL) // If elem->left is not NULL, then the right most element in the left binary sub tree is the predecessor
    {
        currptr=(*elem)->left;
        while(currptr->right != NULL)
        {
            currptr=currptr->right;
        }
        return(currptr->element);
    }
    else
    {
        struct node *prevptr;
        currptr=(*elem);
        prevptr=currptr->parent;
        while(prevptr!=NULL && currptr==(prevptr)->left) // traverse through the tree up till we get a predecessor,if we couldnt find any, then print a message saying No predecessor         
        {
            currptr=prevptr;
            prevptr=currptr->parent;
        }
        if(prevptr==NULL)
        {
            return(-2);
        }
        else
        {
           return(prevptr->element); 
        }
    }
}

// Function to find the successor of the element of the node which elem1 is pointing to
int successor(struct node **elem1,struct node **root)
{
    struct node *currptr;
    if((*elem1)==NULL) // If elem1 pointer is NULL, then print an error message in the main function
    {
        return(-1);
    }
    else if((*elem1)->right != NULL)// If elem1->right is not NULL, then the left most element in the right binary sub tree is the successor
    {
        currptr=(*elem1)->right;
        while(currptr->left != NULL)
        {
            currptr=currptr->left;
        }
        return(currptr->element);
    }
    else
    {
        struct node *prevptr;
        currptr=(*elem1);
        prevptr=currptr->parent;
        while(prevptr!=NULL && currptr==(prevptr)->right) // traverse through the tree up till we get a successor,if we couldnt find any, then print a message saying No successor      
        {
            currptr=prevptr;
            prevptr=currptr->parent;
        }
        if(prevptr==NULL)
        {
            return(-2);
        }
        else
        {
            return(prevptr->element);
        }
    }
}

// Function to implement delete function
struct node* delete(struct node *elem2,struct node *root)
{
    if((elem2->left)==NULL && (elem2->right)==NULL) // If the elem2 does not have bot left and right nodes, then free the memory allocated for elem2
    {
        if(elem2->parent!=NULL )
        {
            // Set the elem2->parent left as null if elem2 is present in left of elem2->parent
            if(elem2->parent->left==elem2) 
            {
                elem2->parent->left=NULL;
            }
            // Set the elem2->parent right as null if elem2 is present in right of elem2->parent
            else
            {
                elem2->parent->right=NULL;
            }
            free(elem2);
            return(root);
        }
        else // If elem2->parent==NULL, then just free elem2 and return NULL
        {
            free(elem2);
            return(NULL);
        }
    }
    // If elem2 has only one side present either left or right
    else if(elem2->left!=NULL && elem2->right==NULL)
    {
        if(elem2->parent!=NULL)
        {
            if(elem2->parent->right==elem2)
            {
                elem2->parent->right=elem2->left;
            }
            else
            {
                elem2->parent->left=elem2->left;
            }
            elem2->left->parent=elem2->parent;
            free(elem2);
            return(root);
        }
        else
        {
            elem2->left->parent=NULL;
            root=elem2->left;
            free(elem2);
            return(root);
        }
    }
    else if(elem2->right!=NULL && elem2->left==NULL)
    {
        if(elem2->parent!=NULL)
        {
            if(elem2->parent->right==elem2)
            {
                elem2->parent->right=elem2->right;
            }
            else
            {
                elem2->parent->left=elem2->right;
            }
            elem2->right->parent=elem2->parent;
            free(elem2);
            return(root);
        }
        else
        {
            elem2->right->parent=NULL;
            root=elem2->right;
            free(elem2);
            return(root);
        }
    }
    // If both sides nodes are present
    else
    {
        int s;
        s=predecessor(&elem2,&root);
        struct node *sptr;
        sptr=search(&root,s);
        elem2->element=s;
        root=delete(sptr,root);
        return(root);
    }
}

int main()
{
    struct node *root = NULL; //starting with an empty tree
    int menu;
    while(1)
    {
        scanf("%d" , &menu);
        // If menu is equal to 1, then call the insert function
        if(menu==1)
        {
            int x;
            scanf("%d" , &x);
            root=insert(root , x);
        }
        // If menu is equal to 2, then call the search function
        else if(menu==2)
        {
            int x;
            scanf("%d" , &x);
            struct node *a;
            a=search(&root,x);
            if(a==NULL)
            {
                printf("Not Found\n");
            }
            else
            {
                printf("Found\n");
            }
        }
        // If menu is equal to 3, then call the inorder function
        else if(menu==3)
        {
            
            inorder(&root);
        }
        // If menu is equal to 4, then call the preorder function
        else if(menu==4)
        {
            preorder(&root);
        }
        // If menu is equal to 5, then call the postorder function
        else if(menu==5)
        {
            postorder(&root);
        }
        // If menu is equal to 6, then call the predecessor function
        else if(menu==6)
        {
            int y,pred;
            scanf("%d" , &y);
            struct node *elem;
            elem=search(&root,y);
            pred=predecessor(&elem,&root);
            if(pred==-1)
            {
                printf("Invalid Input\n");
            }
            else if(pred==-2)
            {
                printf("No predecessor\n");
            }
            else
            {
                printf("%d\n" , pred);                
            }
        }
        // If menu is equal to 7, then call the successor function
        else if(menu==7)
        {
            int z,succ;
            scanf("%d" , &z);
            struct node *elem1;
            elem1=search(&root,z);
            succ=successor(&elem1,&root);
            if(succ==-1)
            {
                printf("Invalid Input\n");
            }
            else if(succ==-2)
            {
                printf("No successor\n");
            }
            else
            {
                printf("%d\n" , succ);                
            }
        }
        // If menu is equal to 8, then call the delete function
        else if(menu==8)
        {
            int z;
            scanf("%d" , &z);
            struct node *elem2;
            elem2=search(&root,z);
            if(elem2==NULL)
            {
                printf("Deletion Fail\n");
            }
            else
            {
                root=delete(elem2,root);
            }
        }
        // If menu is equal to 9, then terminate the program successfully
        else if(menu==9)
        {
           return 0; 
        }
        else
        {
            return -1;
        }
    }
}