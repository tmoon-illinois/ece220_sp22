#include <stdio.h>
#include <stdlib.h>

typedef struct NODE t_node;
struct NODE{
    t_node *left;
    t_node *right;
    int val;
};

t_node *maxBST(t_node *node){
    if(node->right == NULL)
        return node;
    return maxBST(node->right);
}
t_node *minBST(t_node *node){
    if(node->left== NULL)
        return node;
    return minBST(node->left);
}
t_node *NewNode(int val){
    t_node *temp = (t_node*) malloc(sizeof(t_node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

t_node* InsertNode(t_node *node, int data){   
    //base case : Found a right place to insert the node. 
    if(node ==NULL){
        return NewNode(data);
    }
    // recursive case: Traverse either to the left (new data is smaller) or the right (new data is larger) 
    else{
        if(data < node->val)
            node->left = InsertNode(node->left , data);
        else
            node->right = InsertNode(node->right , data);
        // return the unchanged node
        return node;
    }
}
void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(t_node *root, int level)
{
    if(root == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(root->right,level+1);
        padding('\t', level);
        printf("%d\n", root->val);
        printTree(root->left, level+1);
    }
}
/* Function to determine if given Binary Tree is a BST or not by keeping a valid range (starting from [MIN_VALUE, MAX_VALUE]) and keep shrinking it down for each node as we go down recursively */
int isBST(t_node *node, int min, int max){
    int lBST;
    int rBST;
    // basecase
    if(node == NULL)
        return 1;
    // if node val fall outside of valid range
    if(node->val < min || node->val > max)
        return 0;
    // recursivley check left/right subtree with updated range
    lBST = isBST(node->left, min, node->val);
    rBST = isBST(node->right, node->val, max);

    return lBST && rBST;
}
int main(){
    t_node *root = NULL;
    root = NewNode(10);
    root->left = NewNode( 3);
    root->right= NewNode( 15);
    root->left->left = NewNode( 1);
    //root->left->right = NewNode( 2);
    root->left->right = NewNode( 4);

    printTree(root, 0);
    t_node *maxnode = maxBST(root);
    t_node *minnode = minBST(root);
    int min = minnode->val;
    int max = maxnode->val;


    // LC3 from here
    int flag;
    flag = isBST(root, minnode->val, maxnode->val);
    //printf("is it BST? %d\n", sum); 

}
