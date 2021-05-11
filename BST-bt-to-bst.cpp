// convert binary tree to bst
#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void storeTreeIntoVector(node *root, vector<int> &v){

	if(root){
		storeTreeIntoVector(root->left,v);
		v.push_back(root->data);
		storeTreeIntoVector(root->right,v);
	}
}

void insertIntoTree(node *root, vector<int> &v){

	static int i=0;
	if(root){
		insertIntoTree(root->left,v);
		root->data=v[i++];
		insertIntoTree(root->right,v);
	}
}

void inOrderTraversal(node *root){

	if(root){
		inOrderTraversal(root->left);
		cout<<root->data<<" ";
		inOrderTraversal(root->right);
	}
}

int main(){

	node *root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 

    vector<int> v;
    storeTreeIntoVector(root,v);

    sort(v.begin(),v.end());
    
    insertIntoTree(root,v);
    
    inOrderTraversal(root);

    return 0;
}