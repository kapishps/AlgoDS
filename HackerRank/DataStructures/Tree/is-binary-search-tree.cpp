/*The Node struct is defined as follows:
struct Node {
    int data;
    Node* left;
    Node* right;
}
*/

// https://www.hackerrank.com/challenges/is-binary-search-tree

//2nd Solution (better)
bool checkBSTUtil(struct Node* node, int min, int max) {
    if (node==NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return checkBSTUtil(node->left, min, node->data-1) && checkBSTUtil(node->right, node->data+1, max);
}

bool checkBST(Node* root) {
    return (checkBSTUtil(root, -1, 10001));
}


//1st Solution
void inorderrecursive(Node *root,vector<int> &v) {
    if(root!=NULL) {
        inorderrecursive(root->left,v);
        v.push_back(root->data);
        inorderrecursive(root->right,v);
    }
}
bool checkBST(Node* root) {
    if(root!=NULL){
        vector<int> v;
        inorderrecursive(root,v);
        for(int i=1;i<v.size();i++){
            if(v[i-1]>=v[i])
                return false;
        }
        return true;
    }
    else
        return true;
}