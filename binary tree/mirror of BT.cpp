#include <bits/stdc++.h>
using namespace std;

typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;
 
// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
// Helper function to print Inorder traversal
void inorder(node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void mirrorify(node *root){
    if(root==NULL){
        return;
    }
    
    node* n1=root->left;
    node *n2=root->right;
    root->right=n1;
    root->left=n2;
    mirrorify(n1);
    mirrorify(n2);
}

int main()
{
 
    node* tree = createNode(2);
    //node *tree=NULL;
    tree->left = createNode(1);
    tree->right = createNode(8);
    tree->left->left = createNode(12);
    tree->right->right = createNode(9);
 
    // Print inorder traversal of the input tree
    printf("Inorder of original tree: ");
    inorder(tree);
    //node* mirror = NULL;
    mirrorify(tree);
 
    // Print inorder traversal of the mirror tree
    printf("\nInorder of mirror tree: ");
    inorder(tree);
 
    return 0;
}
