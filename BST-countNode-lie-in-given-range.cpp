
// Count BST nodes that lie in a given range 

   void inorder(Node *root,int l,int h,int &count){
       
       if(root){
           
           
           inorder(root->left,l,h,count);
           
            if(root->data>=l and root->data<=h){
                
                count++;
            }
            
             inorder(root->right,l,h,count);
       }
   }
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  
  
    int count=0;
    
      inorder(root,l,h,count);
      
      return count;
}
