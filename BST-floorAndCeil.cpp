#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};


Node *newNode(struct Node *root,int x){

 
   if(root==NULL){
    root=new Node();
   root->data=x;
   root->left=NULL;
   root->right=NULL;
   }

   else if(x<=root->data){
       root->left=newNode(root->left,x);
   }
   else{
       root->right=newNode(root->right,x);
   }
   return root; 

}



void inorder(Node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    
}
void findceilfloor(struct Node *root,int &ceil,int &floor,int key){


    if(root==NULL){
        return;
    }

    if(root->data==key){
        ceil=root->data;
        floor=root->data;
    }
    if(key<root->data){
        ceil=root->data;
        findceilfloor(root->left,ceil,floor,key);
    }
    else{
        floor=root->data;
        findceilfloor(root->right,ceil,floor,key);
    }
}

int main(){
 
   struct Node*root=NULL;
   int ceil=-1,floor=-1;
  root= newNode(root,8);
  root= newNode(root,4);
  root= newNode(root,12);
  root= newNode(root,2);
  root= newNode(root,6);
  root= newNode(root,10);
  root= newNode(root,14);
 //    inorder(root);

   findceilfloor(root,ceil,floor,5);
   cout<<floor<<" "<<ceil<<"\n";

    return 0;



}
