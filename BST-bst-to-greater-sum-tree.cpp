// 1038. Binary Search Tree to Greater Sum Tree

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
    
      void solve(TreeNode *root,stack<TreeNode*>&st){
          
          if(!root) return ;
          
          solve(root->left,st);
           st.push(root);
          solve(root->right,st);
      }
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*>st;
        
        solve(root,st);
        
         TreeNode *t=st.top();
        st.pop();
    int prev=t->val;
        
        while(!st.empty()){
            
            TreeNode *temp=st.top();
            st.pop();
            
            temp->val=temp->val+prev;
            
            prev=temp->val;
            
            
        }
        
        return root;
    }
};
