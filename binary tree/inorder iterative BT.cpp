#include <bits/stdc++.h>
using namespace std;

typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;

node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(node *root){
    stack<node*> stack;
    
    while(root!=NULL||!stack.empty()){
        if(root!=NULL){
            stack.push(root);
            root=root->left;
        }
        else{
            node* temp= stack.top();
            stack.pop();
            cout<<temp->val<<" ";
            root=temp->right;
        }
    }
}


int main()
{
 
    node* tree = createNode(2);
    //node *tree=NULL;
    tree->left = createNode(1);
    tree->right = createNode(8);
    tree->left->left = createNode(12);
    tree->right->right = createNode(9);
 
    inorder(tree);
    //node* mirror = NULL;
    // mirrorify(tree);
 
    // // Print inorder traversal of the mirror tree
    // printf("\nInorder of mirror tree: ");
    // inorder(tree);
 
    return 0;
}
