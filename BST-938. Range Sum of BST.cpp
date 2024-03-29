// 938. Range Sum of BST

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
    int sum=0;
    TreeNode* solve(TreeNode*root,int low,int high){
        
        if(!root){
            return NULL;
        }
        
        
        TreeNode* left=solve(root->left,low,high);
        
         if(root->val>=low and root->val<=high){
            
            sum+=root->val;
        }
        TreeNode* right=solve(root->right,low,high);
        
     
        
       
        
        return NULL;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
     
        
           solve(root,low,high);
        
           return sum;
    }
};
