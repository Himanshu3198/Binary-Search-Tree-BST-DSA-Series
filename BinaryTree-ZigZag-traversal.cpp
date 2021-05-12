
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        vector<vector<int>>ans;
        
        if(root==NULL){
            return ans;
        }
        
          stack<TreeNode*>s1,s2;
        
        s1.push(root);
        
        while(!s1.empty() or !s2.empty()){
            
            vector<int>v1,v2;
            
            while(!s1.empty()){
                
                TreeNode* cur=s1.top();
                s1.pop();      
                
                
                if(cur->left!=NULL){
                    
                    s2.push(cur->left);
                }
                
                if(cur->right!=NULL){
                    s2.push(cur->right);
                }
                
                v1.push_back(cur->val);
                
                
            }
            
            
            ans.push_back(v1);
            
           
            
            while(!s2.empty()){
                TreeNode*cur1=s2.top();
                s2.pop();
                
                
                
                if(cur1->right!=NULL){
                    
                    s1.push(cur1->right);
                        
                    
                }
                
                if(cur1->left!=NULL){
                    s1.push(cur1->left);
                }
                
                v2.push_back(cur1->val);
                
            }
            
            if(v2.size()>0){
                  ans.push_back(v2);
            }
            
          
           
        }
        
        return  ans;
        
        
        
        
    }
};
