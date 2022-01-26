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
    
    
      void preOrder(TreeNode *root,vector<int>&res){
          
          
          if(!root) return;
          
          preOrder(root->left,res);
          res.push_back(root->val);
          preOrder(root->right,res);
      }
    
     
    void merge(vector<int>res1,vector<int>res2,vector<int>&res){
        
        
        
        int n=res1.size(),m=res2.size();
        
        int i=0,j=0,k=0;
        
        
        while(i<n and j<m){
            
            if(res1[i]<res2[j]){
                
                res[k]=res1[i];
                i++;
                k++;
            }else{
                
                res[k]=res2[j];
                j++;
                k++;
            }
        }
        
        
        while(i<n){
            
            res[k]=res1[i];
            i++;
            k++;
        }
        
        while(j<m){
            res[k]=res2[j];
            j++;
            k++;
        }
    }
    
      
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        
        
        vector<int>res1,res2;
        
        preOrder(root1,res1);
        preOrder(root2,res2);
        
        vector<int>res(res1.size()+res2.size());
        
        merge(res1,res2,res);
        return res;
        
    }
};
