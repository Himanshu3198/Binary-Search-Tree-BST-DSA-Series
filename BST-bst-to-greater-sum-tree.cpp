        int prevTotal=0;
    void transformTree(struct Node *root)
    {
        //code here
         // we will use property of reverse inorder because inorder gives a sorted list in asceding
        //   order but if we do reverse inorder like visit right child first then it will be in 
        // descending order
        
        if(!root) return ;
         transformTree(root->right);
         int temp=root->data;
         
         root->data=prevTotal;
         prevTotal+=temp;
         
         transformTree(root->left);
         
    }
