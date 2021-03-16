// lowest common ancestor in bst;
#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int x){
  struct Node*newnode=new Node();
  newnode->data=x;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;

}

 int LCA(Node *root, int n1, int n2)
{
   //Your code here
     if(root==NULL){
             return NULL;
         }
      if(root->data>n1 && root->data>n2){
          return LCA(root->left,n1,n2);
      }
      if(root->data<n1 && root->data<n2){
          return LCA(root->right,n1,n2);
      }
      return root->data;
    
         
}

int main(){

    struct Node *root;
    root=newNode(5);
    root->left=newNode(4);
    root->left->left=newNode(3);
    root->right=newNode(6);
    root->right->right=newNode(7);
    root->right->right->right=newNode(8);
    cout<<LCA(root,7,8);
    return 0;
}