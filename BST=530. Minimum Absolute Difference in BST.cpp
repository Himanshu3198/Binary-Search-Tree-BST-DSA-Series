// 530. Minimum Absolute Difference in BST

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
      vector<int>v;
       void dfs(TreeNode *root){
           
             if(!root){
                 return;
                 
             }
         
           dfs(root->left);
             v.push_back(root->val);
           dfs(root->right);
       }
    int getMinimumDifference(TreeNode* root) {
        
         
        
     
          dfs(root);
        int ans=INT_MAX;
        
        for(int i=0;i<v.size()-1;i++){
            
            ans=min(ans,abs(v[i]-v[i+1]));
        }
        
        return ans;
        
        
         
    }
};
