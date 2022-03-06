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

class bst{
    
    public:
       int mn;
       int mx;
       int sum;
    
      bst(int mn_,int mx_,int sum_){
          
          mn=mn_;
          mx=mx_;
          sum=sum_;
      }
};
class Solution {
public:
     int ans=INT_MIN;
    
    
    bst solve(TreeNode *root){
        
        if(!root) return bst(INT_MAX,INT_MIN,0);
        
         
        
        bst left=solve(root->left);
        bst right=solve(root->right);
        
          int x=root->val;
        if(root->val>left.mx and root->val<right.mn){
            
             ans=max(ans,x+left.sum+right.sum);
             return  bst(min(x,left.mn),max(x,right.mx),left.sum+right.sum+x);
//             if(root->left and root->right){
                
//                 ans=max(ans,x+left.sum+right.sum);
//                  return bst(left.mn,right.mx,x+left.sum+right.sum);
//             }else if(root->left){
                
//                 ans=max(ans,x+left.sum);
//                 return bst(left.mn,x,x+left.sum);
//             }else if(root->right){
                
//                 ans=max(ans,x+right.sum);
//                 return bst(x,right.mx,x+right.sum);
//             }else{
//                 ans=max(ans,x);
//                 return bst(x,x,x);
//             }
            
        }else{
            
            return bst(INT_MIN,INT_MAX,0);
        }
        
    }
    
     

     
    int maxSumBST(TreeNode* root) {
        
         solve(root);
      
        return ans<0?0:ans;
        
    }
};
