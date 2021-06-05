
// 99. Recover Binary Search Tree
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


//  algorithm
// 1. traverse tree in in-order fashion
// 2. keep track of prev node 
// 3. if prev node not null  and current node value is less than prev node than mark start point as prev node and end point as curr node 
// 4. after completion of traversal swap value of start point node and end point node
class Solution {
public:
    
    void helper(TreeNode *root,TreeNode* &prev,TreeNode* &start_point,TreeNode* &end_point){
        
        if(!root) return;
         helper(root->left,prev,start_point,end_point);
        if(prev){
            if(root->val<prev->val){
                
                 if(!start_point){
                start_point=prev;
                  }
                
                  end_point=root;
            }
           
          
        }
        
        prev=root;
          helper(root->right,prev,start_point,end_point);
        
    }
    void recoverTree(TreeNode* root) {
        
        TreeNode *prev=NULL,*start_point=NULL,*end_point=NULL;
        
        helper(root,prev,start_point,end_point);
        
        swap(start_point->val,end_point->val);
    }
};
