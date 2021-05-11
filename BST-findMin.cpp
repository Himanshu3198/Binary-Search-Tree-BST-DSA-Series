int solve(Node*root){
     
     
      if(root->left==NULL){
          
          return root->data;
      }
      solve(root->left);
   
   
 }
int minValue(Node* root)
{
    // Code here
    
    int minval=INT_MAX;
    
     return solve(root);
      
      
}
