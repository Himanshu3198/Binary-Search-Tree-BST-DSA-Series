
//  time complexity O(N)
// space complexity O(1)
class bst{
    public:
    int maxnode;
    int minnode;
    int maxsize;
    
    bst(int _mxnode,int _mnnode,int _mxsize){
        
        maxnode=_mxnode;
        minnode=_mnnode;
        maxsize=_mxsize;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    int maxSize=INT_MIN;
    
    bst solve(Node *root){
        
        if(!root) return bst(INT_MIN,INT_MAX,0);
        
        bst left=solve(root->left);
        bst right=solve(root->right);
        
        if(root->data>left.maxnode and root->data<right.minnode){
            
          maxSize=max(maxSize,left.maxsize+right.maxsize+1);
          return bst(max(root->data,right.maxnode),min(root->data,left.minnode),
          left.maxsize+right.maxsize+1);
        
        }else{
            
            return bst(INT_MAX,INT_MIN,0);
        }
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	solve(root);
    	return maxSize;
    	
    }
