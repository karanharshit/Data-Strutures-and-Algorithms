#include <bits/stdc++.h>
#include<string>
using namespace std;

/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* stringtoTree(string str){
    int data=str[0]-'0';
    Node* root = newNode(data);
    stack<Node*> s;
    s.push(root);
    for(int i=1;i<str.length();i++){
        if(str[i]!='('&&str[i]!=')'){
            //data=stoi(s[i]);
            data=str[i]-'0';
            Node *temp=s.top();
            Node *newN = newNode(data);
            if(temp->left==NULL){
                temp->left=newN;
            }
            else{
                temp->right=newN;
            }
            s.push(newN);
        }
        else if(str[i]==')'){
            s.pop();
        }
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    //string str = "4(2(3)(1))(6(5))";
    string str="1(2(3(4(5(6(7(8)))))))";
    Node *root = stringtoTree(str);
    inorder(root);
    return 0;
}
