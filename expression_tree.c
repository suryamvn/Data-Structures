#include<stdio.h>
#include<stdlib.h>

struct node // Define structure for node in bst
{
    char element;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct stack // Define structure for stack node
{
  struct node *ref;
  struct stack *next;
};

void Push(struct node *op,struct stack **top) //Function to push the element
{
    struct stack *inpptr;
    inpptr = (struct stack *)malloc(sizeof(struct stack));
    inpptr->ref=op;
    inpptr->next = NULL;
    //if the stack is empty, then point top to this element
    if ((*top) == NULL) 
    {
        *top = inpptr;
        return;
    }
    //if the stack is not empty, then push the element
    else if ((*top) != NULL) 
    {
        inpptr->next = *top;
        *top = inpptr;
        return;
    }
    // if the push operation fails, then print a message
    else 
    {
        printf("Push Failure\n");
    }
}

void Pop(struct stack **top) // Function to pop top element
{
    //if Pop operation fails, then print a message saying the same
    if ((*top) == NULL) 
    {
        printf("Pop Failure\n");
    }
    //pop the top elementin the stack
    else  
    {
        struct stack *popptr;
        popptr = *top;
        *top = (*top)->next;
        //Deallocate the memory which is allocated for popptr
        free(popptr);
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
        if((*root)->left != NULL)
        {
            printf("(");
        }
        inorder(&((*root) -> left));
        printf("%c" , (*root) -> element);
        inorder(&((*root) -> right));
        if((*root)->right != NULL)
        {
            printf(")");
        }
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
        printf("%c" , (*root) -> element);
        preorder(&((*root) -> left));
        preorder(&((*root) -> right));
    }
}



int main()
{
    struct node *root; // root pointer points to the root node of the tree
    struct stack *top; // top points to the top element in the stack
    top=NULL;
    char str[500];
    // Take input of the string str
    scanf("%s" , str);
    int i=0;
    while(str[i]!='\0')
    {
        // If str[i] is an operand, then push the character into the stack
        if(str[i]>='a' && str[i]<='z')
        {
            struct node *operand;
            operand=(struct node *) malloc(sizeof(struct node));
            if(operand==NULL)// If memory allocation failed, print an error message
            {
                printf("Error allocating memory\n");
                exit(1);
            }
            operand->element=str[i];
            operand->left=NULL;
            operand->right=NULL;
            operand->parent=NULL;
            Push(operand,&top);
        }
        // If str[i] is an operator, then pop the top two characters and place it in the bst where the root character is the operator
        else
        {
            struct node *operatr;
            operatr=(struct node *) malloc(sizeof(struct node));
            if(operatr==NULL)// If memory allocation failed, print an error message
            {
                printf("Error allocating memory\n");
                exit(1);
            }
            operatr->element=str[i];
            operatr->left=NULL;
            operatr->right=NULL;
            operatr->parent=NULL;
            root=operatr;
            operatr->right=top->ref;
            Pop(&top);
            operatr->left=top->ref;
            Pop(&top);
            Push(operatr,&top);
        }
        i++;
    }
    // The inorder traversal of the expression tree will be the infix expression
    inorder(&root);
    printf("\n");
    // The preorder traversal of the expression tree will be the prefix expression
    preorder(&root);
    printf("\n");
    return 0;
}