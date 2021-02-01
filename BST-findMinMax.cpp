// find minimum and maximum element in binary search tree
// time complexity O(h) 
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int data)
{
    Node *newnode = new Node();
    newnode->data=data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *Insert(Node *root, int data)
{

    if (root == NULL)
    {
        root = NewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else if (data >= root->data)
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int FindMin(Node *root)
{

    if (root == NULL)
    {
        cout << "tree is empty\n";
        return (-1);
    }

    else if (root->left == NULL)
    {
        return (root->data);
    }
    return FindMin(root->left);
}
int FindMax(Node *root)
{

    if (root == NULL)
    {
        cout << "tree is empty\n";
        return (-1);
    }

    else if (root->right == NULL)
    {
        return (root->data);
    }
    return FindMax(root->right);
}

void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data<<"\n ";
    inorder(root->right);
}

int main()
{
    Node *root=NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 17);
    root = Insert(root, 25);
    // inorder(root);
   cout<< FindMin(root)<<"\n";
     cout<< FindMax(root);
    return 0;
}
