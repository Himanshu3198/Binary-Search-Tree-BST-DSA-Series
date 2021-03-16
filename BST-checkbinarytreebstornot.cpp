#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node*left,*right;

};

Node *newNode(int key){

  struct  Node *newnode=new Node();

  newnode->data=key;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
// bool check=true;

    bool isValidBST(Node* root) {
        
        stack<Node*>s;
        long maxval=LONG_MIN;
        
        while(!s.empty() || root!=NULL){
            
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            
            Node *givetop=s.top();
                    s.pop();
            
            int minval=givetop->data;
            if(minval<=maxval){
                return false;
            }
            maxval=minval;
            root=givetop->right;
              
        }
        return true;
        
    }

int main(){
    struct Node *root;
   bool check=false;
    root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(5);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    cout<<isValidBST(root)<<"\n";
    return 0;
}