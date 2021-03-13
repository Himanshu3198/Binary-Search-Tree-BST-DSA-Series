class Solution {
public:

void myFunc(Node* root){
   
    if(root->left!=NULL){
        root->left->next=root->right;
        if(root->next!=NULL){
            root->right->next=root->next->left;
        }
        
        myFunc(root->left);
        myFunc(root->right);
    } 
    
    
}

Node* connect(Node* root) {
    if(root==NULL) return NULL;
    myFunc(root);
    return root;
}
};