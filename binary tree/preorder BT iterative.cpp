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

void preorder(node *root){
    stack<node*> stack;
    
    while(root!=NULL||!stack.empty()){
        if(root!=NULL){
            stack.push(root);
            cout<<root->val<<" ";
            root=root->left;
        }
        else{
            node* temp= stack.top();
            stack.pop();
            // cout<<temp->val<<" ";
            root=temp->right;
        }
    }
}


int main()
{
 
    node* tree = createNode(1);
    //node *tree=NULL;
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);
    // tree->right->left= createNode(10);
    // tree->right->left->left= createNode(9);
    // tree->right->left->right= createNode(11);
 
    preorder(tree);
    //node* mirror = NULL;
    // mirrorify(tree);
 
    // // Print inorder traversal of the mirror tree
    // printf("\nInorder of mirror tree: ");
    // inorder(tree);
 
    return 0;
}
