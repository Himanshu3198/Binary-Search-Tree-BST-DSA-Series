// BST insertion and traversing using inorder traversal

// Time Complexity O(h) where h is height of bst
#include<bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;

};
BstNode * GetNewNode(int data){
    BstNode * newNode=new BstNode();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
BstNode* Insert(BstNode* root,int data){
    if(root==NULL){
        root=GetNewNode(data);
    }
    else if(data<=root->data){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
}

void inorder(BstNode* root){
    if(root==NULL){
       return;
    }
      

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
}


int main(){
    BstNode *root=NULL;
  
    root=Insert(root,15);
     root=Insert(root,10);
     root=Insert(root,25);
     root=Insert(root,55);
     root=Insert(root,65);
      root=Insert(root,12);
       root=Insert(root,8);
        root=Insert(root,5);
    
       inorder(root);
       return 0;

}
