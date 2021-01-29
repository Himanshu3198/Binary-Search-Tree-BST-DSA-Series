/* binary search tree deletion of node 
  time Complexity O(n) */

#include<bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode *left;     //node declaration
    BstNode *right;

};
BstNode * GetNewNode(int data){
    BstNode * newNode=new BstNode();
    newNode->data=data;                           //creating new node 
    newNode->left=newNode->right=NULL;           //set left and right to null
    return newNode;
}
BstNode* Insert(BstNode* root,int data){
    if(root==NULL){
        root=GetNewNode(data);                 //base case
    } 
    else if(data<=root->data){
        root->left=Insert(root->left,data);        //cheacking   null part left root node 
    }
    else{
        root->right=Insert(root->right,data);  //cheacking   null part  of right root node 
    }
    return root;
}


BstNode* findMin(BstNode* root){
    while(root->left!= NULL) {
        root=root->left;     // find max element  on left part of tree so that we make it root node
    } 
    return root;
}

BstNode* Delete(BstNode* root,int data){
    if(root==NULL)
    {
        return root;     
    }
   else if(data<root->data){ 
       root->left=Delete(root->left,data);          // search the element to be delete on left part of tree
       }
   else if(data>root->data){
       root->right=Delete(root->right,data);          // search the element to be delete on left part of tree
       }

       else{
              // When element found in tree
               // case 1 No Child
           if(root->left==NULL && root->right==NULL){
               delete root;
               root=NULL;
           }
                      //case 2:  1 child  only  have right child
           else if(root->left==NULL){
               struct BstNode* temp=root;            //suppose address of delete element is 500 and  single child address is 600 we store address of deleted element 
                                                    // in temp  and we link the next child address to address of root and then delete  address of element that would be delete
               root=root->right;                    
               delete temp;
           }
                 //case 2:  1 child  only  have left child
           else if(root->right=NULL){
               struct BstNode* temp=root;             
               root=root->left;
               delete temp; 
           }

           else{
                //case 3 two child
               struct BstNode* temp=findMin(root->right);
                 root->data=temp->data;                                          /*while having 2 children we replace  deleting node data to 
                                                                                    max element on left hand side of tree  and delete that max element*/
                 root->right=Delete(root->right,temp->data);
           }


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
       root=Delete(root,12);
       cout<<"\n";
         inorder(root);
       return 0;

}
