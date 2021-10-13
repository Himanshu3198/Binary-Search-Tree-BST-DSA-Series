// 1008. Construct Binary Search Tree from Preorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
        void solve(TreeNode*root,int x){
            
            
             if(root==NULL){
                 return;
             }
               if(x<root->val){
                   if(root->left!=NULL){
                     solve(root->left,x);   
                   }
                   else{
                         root->left=new TreeNode(x);
                   }
                    
                
                 
               }
               else if(x>root->val){
                  if(root->right!=NULL){
                       solve(root->right,x);
                  }
                   else{
                      root->right=new TreeNode(x);  
                   }
                  
        
               }
           
        
            return;
            
            
        }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     
         TreeNode *root=new TreeNode(preorder[0]);
        
        
        for(int i=1;i<preorder.size();i++){
            
            
            solve(root,preorder[i]);
        }
        
        return root;
    }
};
