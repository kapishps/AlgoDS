#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define Boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

const int inf = 2147483647;
const int MOD = 1e9+7;
const int MAXN = 1e5+9;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*----------------------- Nonrecursive Preorder --------------------------*/
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode *> st;
    if(root)
        st.push(root);
    vector<int> v;
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        v.push_back(curr->val);
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
    }
    return v;
}


/*----------------------- Nonrecursive inorder --------------------------*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while(!st.empty() || curr){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode *temp = st.top();
            v.push_back(temp->val);
            st.pop();
            curr = temp->right;
        }
    }
    return v;
}


/*----------------------- Nonrecursive Postorder --------------------------*/
vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    if(root)
        st.push(root);
    vector<int> v;
    while(!st.empty()){
        TreeNode *curr = st.top();
        st.pop();
        v.push_back(curr->val);
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
    }
    reverse(v.begin(),v.end());
    return v;
}


/*----------------------- Inorder Successor in BST --------------------------*/
TreeNode *findnode(TreeNode *root, int val){    //return node containing val
    if(root->val == val)
        return root;
    while(root->val != val){
        if(root->val > val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

TreeNode* getSuccessor(TreeNode* root, int B) {
    TreeNode *curr = findnode(root,B);
    if(curr == NULL)
        return NULL;
    if(curr->right){            // curr has right subtree
        TreeNode *temp = curr->right;
        while (temp->left){
            temp = temp->left;
        }
        return temp;
    }
    else{                       // curr does not have right subtree
        TreeNode *successor = NULL;
        TreeNode *ancestor = root;
        while(ancestor != curr){
            if(ancestor->val > curr->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

/*----------------------- Check valid BST --------------------------*/
bool issubtreelesser(TreeNode *root,int val){
    if(root==NULL)
        return 1;
    if(root->val >= val)
        return 0;
    return (issubtreelesser(root->left,val) && issubtreelesser(root->right,val));
}

bool issubtreegreater(TreeNode *root,int val){
    if(root==NULL)
        return 1;
    if(root->val <= val)
        return 0;
    return (issubtreegreater(root->left,val) && issubtreegreater(root->right,val));
}

int isValidBST(TreeNode* root) {
    if(root==NULL)
        return 1;
    if(issubtreelesser(root->left,root->val) && issubtreegreater(root->right,root->val)
       && isValidBST(root->left) && isValidBST(root->right))
        return 1;
    else
        return 0;
}


/*----------------------- Height-balanced binary tree --------------------------*/
int heightoftree(TreeNode *root){
    if(root==NULL)
        return 0;
    return (1 + max(heightoftree(root->right),heightoftree(root->left)));
}

int isBalanced(TreeNode* root) {        //check alternate soln below
    if(root == NULL)
        return 1;
    if(isBalanced(root->left) && isBalanced(root->right) &&
       abs(heightoftree(root->left)-heightoftree(root->right)) < 2)
        return 1;
    return 0;
}


/*-------------------- Height-balanced binary tree(efficient) -----------------------*/
pair<int,bool> util(TreeNode *root) {
    if (root == NULL) {
        return make_pair(0, 1);
    }
    pair<int, bool> result, r = util(root->right), l = util(root->left);
    result.first = 1 + max(r.first, l.first);
    result.second = (r.second && l.second && (abs(r.first - l.first) < 2));
    return result;
}

int isbalanced(TreeNode* root) {
    if(root == NULL)
        return 1;
    if(util(root).second)
        return 1;
    return 0;
}

/*----------------------- Identical Binary Trees --------------------------*/
int isSameTree(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL)
        return 1;
    if((A==NULL && B!=NULL) || (A!=NULL && B==NULL) || (A->val != B->val))
        return 0;
    return isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
}

/*----------------------- Symmetric Binary Tree --------------------------*/
TreeNode *mirrorTree(TreeNode* root) {
    if (root != NULL) {
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        mirrorTree(root->right);
        mirrorTree(root->left);
    }
    return root;
}

int isSymmetric(TreeNode* root) {
    if(root==NULL)
        return 1;
    return ::isSameTree(root->left,::mirrorTree(root->right));
}


/*----------------------- Symmetric Binary Tree(alternate) --------------------------*/
bool issymmetricutil(TreeNode *A,TreeNode *B) {
    if (A == NULL && B == NULL)
        return 1;
    if ((A != NULL && B == NULL) || (A == NULL && B != NULL))
        return 0;
    return (issymmetricutil(A->left, B->right) && issymmetricutil(A->right, B->left));
}

int issymmetric(TreeNode* root) {
    if(root==NULL)
        return 1;
    return issymmetricutil(root->left,root->right);
}


/*----------------------- Max Depth Of Binary Tree --------------------------*/
int maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    return (1 + max(maxDepth(root->right),maxDepth(root->left)));
}


/*----------------------- Min Depth Of Binary Tree --------------------------*/
int minDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    if(root->left != NULL && root->right ==NULL)
        return 1 + minDepth(root->left);
    else if(root->left == NULL && root->right !=NULL)
        return 1 + minDepth(root->right);
    else
        return 1 + min(minDepth(root->left),minDepth(root->right));
}


/*----------------------- Sum Root To Leaf Numbers --------------------------*/
int dfs(TreeNode *root,int n){
    if(root == NULL)
        return 0;
    n = (n*10 + root->val)%1003;
    if(root->left==NULL && root->right==NULL)
        return n;
    return (dfs(root->left,n)+dfs(root->right,n))%1003;
}

int sumNumbers(TreeNode* root) {
    if(root == NULL)
        return 0;
    return dfs(root,0)%1003;
}


/*----------------------- Root To Leaf Paths With Sum --------------------------*/
void dfs(TreeNode *root,vector<vector<int> > &result,int sum, vector<int> v){
    if(root==NULL)
        return;
    v.push_back(root->val);
    sum -= root->val;
    if(root->left==NULL && root->right==NULL){
        if(sum==0){
            result.push_back(v);
        }
        return;
    }
    dfs(root->left,result,sum,v);
    dfs(root->right,result,sum,v);
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > result;
    if(root==NULL)
        return result;
    vector<int> v;
    dfs(root,result,sum,v);
    return result;
}


/*----------------------- Paths Sum --------------------------*/
int hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)
        return 0;
    sum -=root->val;
    if(root->left==NULL && root->right==NULL && sum==0)
        return 1;
    return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
}

int main() {
    Boost;

    return 0;
}
