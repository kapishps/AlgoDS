#include <iostream>
#include <stack>

using namespace std;

struct binarytreenode {
    int data;
    binarytreenode *right;
    binarytreenode *left;
};

void preordernonrecursive(binarytreenode *root) {
    stack<binarytreenode *> st;
    while(1) {
        while(root!=NULL) {
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;
        }
        if(st.empty())
            break;
        root=st.top();

        root=root->right;
        st.pop();
    }
}

void preorderrecursive(binarytreenode *root) {
    if(root!=NULL) {
        cout<<root->data<<" ";
        preorderrecursive(root->left);
        preorderrecursive(root->right);

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
    preordernonrecursive(root);
    return 0;
}