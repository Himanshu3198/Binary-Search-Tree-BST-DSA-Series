    
      bool solve(Node *root,int a,int b){
          
          if(!root){
              return true;
          }
          
          if(root->data<=a or root->data>=b){
              return false;
          }
          
          
            return solve(root->left,a,root->data) and solve(root->right,root->data,b);
      }
    bool isBST(Node* root) 
    {
        // Your code here
        
     
          return solve(root,INT_MIN,INT_MAX);
          
           
           
    }
