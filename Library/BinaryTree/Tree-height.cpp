#include <iostream>

using namespace std;

struct binarytreenode {
    int data;
    binarytreenode *right;
    binarytreenode *left;
};

int heightoftree(binarytreenode *root) {
    int left,right;
    if(root==NULL)
        return 0;
    else{
        left=heightoftree(root->left);
        right=heightoftree(root->right);
        if(left>right)
            return(left+1);
        else
            return(right+1);
    }
}

binarytreenode* newNode(int data) {
    binarytreenode* node = new binarytreenode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main() {
    /* Constructed binary tree is
            1
          /   \
         2     3
        / \   /
       4   5  6
    */
    binarytreenode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    cout<<heightoftree(root);
    return 0;
}