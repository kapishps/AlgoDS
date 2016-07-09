#include <iostream>
#include <stack>

using namespace std;

struct binarytreenode {
    int data;
    binarytreenode *right;
    binarytreenode *left;
};

void postordernonrecursive(binarytreenode *root) {
    stack<binarytreenode *> st1;
    for(int i=0;i<13;i++) {
        if(root!=NULL) {
            st1.push(root);
            root=root->left;
        }
        else {
            if(st1.empty())
                return;
            else if(st1.top()->right==NULL) {
                root=st1.top();
                st1.pop();
                cout<<root->data<<" ";
                if(root==st1.top()->right) {
                    cout<<st1.top()->data<<" ";
                    st1.pop();
                }
            }
            if(!st1.empty())
                root=st1.top()->right;
            else
                root=NULL;
        }
    }
}

void postorderrecursive(binarytreenode *root) {
    if(root!=NULL) {
        postorderrecursive(root->left);
        postorderrecursive(root->right);
        cout<<root->data<<" ";

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
    postordernonrecursive(root);
    return 0;
}