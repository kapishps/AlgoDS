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
    vector<string> ans;
    void dfs(TreeNode* root, vector<int> &t){
        t.push_back(root->val);
        if(root->left){
            dfs(root->left, t);
        }
        if(root->right) {
            dfs(root->right, t);
        }
        if(root->left == NULL && root->right == NULL){
            string temp;
            for(auto i: t){
                temp += to_string(i);
                temp += "->";
            }
            ans.push_back(temp.substr(0, temp.size()-2));
        }
        t.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> t;
        dfs(root, t);
        return ans;
    }
};