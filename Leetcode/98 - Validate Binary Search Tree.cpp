/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, long mn, long mx){
        if(!root){
            return true;
        }
        
        if(root->val <= mn || root->val >= mx){
            return false;
        }
        
        return check(root->left, mn, root->val) && check(root->right, root->val, mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN -1L, INT_MAX + 1L);
    }
};