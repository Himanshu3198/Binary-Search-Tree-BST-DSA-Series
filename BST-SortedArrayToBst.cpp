
// Convert sorted array to bst

// approach
// use binary search concept


// in sorted array  element before mid is less than mid and after  greater than mid  so in balanced bst we make root as mid and all left element of array as left part of tree and all right 
// right element as right part of tree


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
     
    
    
      TreeNode* solve(TreeNode* &root,vector<int>&nums,int start,int end){
         
          
           if(start>end){
               return NULL;
           }
          
          
          
          
          int mid=(start+end)/2;
          
          
           
           TreeNode* newNode=new TreeNode(nums[mid]);
            root=newNode;

          
         root->left= solve(root->left,nums,start,mid-1);
          
          
           
        root->right=  solve(root->right,nums,mid+1,end);
          
          return root;
           
        
          
      }
    
    
        
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        TreeNode *root=NULL;
        
       return solve(root,nums,0,n-1);
        
        
        
        
    }
};
