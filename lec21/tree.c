#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct nodeTag t_node;
struct nodeTag
{
    int data;
    t_node *left;
    t_node *right;
};

t_node* NewNode(int data);
void DeleteTree(t_node *node);

// Traverse a tree
void preorder(t_node *node);
void inorder(t_node *node);
void postorder(t_node *node);


// Helper functions to print out a tree
void padding(char ch, int n);
void printTree(t_node *node, int level);

// BST
t_node* BSTInsert(t_node *node, int data);
t_node* BSTSearch(t_node *node, int key);

t_node* FindMin(t_node *node);
t_node* FindMax(t_node *node);
int getHeight(t_node *node);

int main(){
    t_node *root = NULL;
    root = BSTInsert(root, 4);
    root = BSTInsert(root, 2);
    root = BSTInsert(root, 5);
    root = BSTInsert(root, 1);
    root = BSTInsert(root, 0);
    root = BSTInsert(root, 100);
    root = BSTInsert(root, 8);

    printTree(root, 0);

}


t_node* BSTInsert(t_node *node, int data)
{
    //base case : Found the right place to insert the node. 
    if(node ==NULL){
        return NewNode(data);
    }
    // recursive case: Traverse either to the left (new data is smaller) or the right (new data is larger) 
    else{
        if(data < node->data)
            node->left = BSTInsert(node->left , data);
        else
            node->right = BSTInsert(node->right , data);
        // return the unchanged node
        return node;
    }
}

t_node* BSTSearch(t_node *node, int key)
{
    // base case
    // 1. no match
    if(node == NULL) 
        return NULL;
    // 2. yes match
    if(node->data == key)
        return node;
    
    // recursive case
    if(key < node->data)
        return BSTSearch(node->left, key);
    else 
        return BSTSearch(node->right, key);
}

void preorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void postorder(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}
void DeleteTree(t_node *node)
{
    // Base case
    if(node ==NULL)
        return;
    // Recursive case
    else{
        printf("Free node of %d\n ", node->data);
        DeleteTree(node->left);
        DeleteTree(node->right);
        free(node);
    }
}
// return the address of a new node
t_node* NewNode(int data)
{
    t_node *node = (t_node*) malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
t_node* FindMin(t_node *node)
{
    //base case
    if(node->left == NULL)
        return node;
    //recursive case
    else
        return FindMin(node->left);
}
t_node* FindMax(t_node *node)
{
    //base case
    if(node->right == NULL)
        return node;
    //recursive case
    else
        return FindMax(node->right);
}
int getHeight(t_node *node)
{
    int lh, rh;
    //base
    if(node == NULL)
        return -1;
    //recursive
    else{
        lh = getHeight(node->left);
        rh = getHeight(node->right);
        if(lh>rh)
            return lh + 1;
        else
            return rh + 1;
    }
}



void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(t_node *node, int level)
{
    if(node == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(node->right,level+1);
        padding('\t', level);
        printf("%d\n", node->data);
        printTree(node->left, level+1);
    }
}
