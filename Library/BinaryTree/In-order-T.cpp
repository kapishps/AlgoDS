#include <iostream>
#include <stack>

using namespace std;

struct binarytreenode {
    int data;
    binarytreenode *right;
    binarytreenode *left;
};

void inordernonrecursive(binarytreenode *root) {
    stack<binarytreenode *> st;
    while(1) {
        while(root!=NULL) {
            st.push(root);
            root=root->left;
        }
        if(st.empty())
            break;
        root=st.top();
        cout<<root->data<<" ";
        root=root->right;
        st.pop();
    }
}

void inorderrecursive(binarytreenode *root) {
    if(root!=NULL) {
        inorderrecursive(root->left);
        cout<<root->data<<" ";
        inorderrecursive(root->right);
    }
}

binarytreenode* newNode(int data) {
    binarytreenode* node = new binarytreenode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int main()
{
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
    inordernonrecursive(root);
    return 0;
}