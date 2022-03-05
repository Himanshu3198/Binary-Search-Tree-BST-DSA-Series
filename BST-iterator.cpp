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
class BSTIterator {
public:
//      tc O(1) O(n)/O(n)=O(1) 
//      sc O(h)
      

      stack<TreeNode*>st;
    
   void  solve(TreeNode *root,stack<TreeNode*>&st){
       
              TreeNode *temp=root;

         while(temp){
             
             st.push(temp);
             temp=temp->left;
         }
         
       
   }
    BSTIterator(TreeNode* root) {
        solve(root,st);
    }
    
    int next() {
        if(hasNext()){
            
           TreeNode * x=st.top();
            st.pop();
            
            if(x->right){
                 solve(x->right,st);
            }
           
            return x->val;
        }
        
        return 0;
        
    }
    
    bool hasNext() {
      
         return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
