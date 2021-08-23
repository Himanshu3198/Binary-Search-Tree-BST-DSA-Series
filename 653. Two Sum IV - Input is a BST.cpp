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
       unordered_set<int>set;
          bool solve(TreeNode *root,int k){
              
              if(root){
                  
                  
                   if( set.size()>0 and set.find(k-root->val)!=set.end()){
                       return true;
                   }
                  else{
                      set.insert(root->val);
                  }
                  
                  return solve(root->left,k) ||solve(root->right,k);
                  
              }
              return NULL;
          }
     
    bool findTarget(TreeNode* root, int k) {
        
        
          if(solve(root,k)){
              return true;
          }
        return false;
        
    }
};
