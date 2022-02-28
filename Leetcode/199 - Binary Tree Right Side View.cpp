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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        int level = 0;
        q.push(root);
        while(!q.empty() && q.front()){
            int j = q.size();
            ans.push_back(-1);
            while(j--){
                TreeNode *t = q.front();
                q.pop();
                ans[level] = t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            level++;
        }
        return ans;
    }
};