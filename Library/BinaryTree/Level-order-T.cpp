#include <iostream>
#include <queue>

using namespace std;

struct binarytreenode {
    int data;
    binarytreenode *right;
    binarytreenode *left;
};

void levelordertraversal(binarytreenode *root){
    binarytreenode *temp;
    queue<binarytreenode *> qu;

    if(root==NULL)
        return;
    qu.push(root);
    while(!qu.empty())
    {
        temp=qu.front();
        cout<<temp->data<<" ";
        qu.pop();
        if(temp->left!=NULL)
            qu.push(temp->left);
        if(temp->right!=NULL)
            qu.push(temp->right);
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
    levelordertraversal(root);
    return 0;
}