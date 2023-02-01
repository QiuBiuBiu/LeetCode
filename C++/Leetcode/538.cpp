/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return solve(root, sum);
    }
    TreeNode* solve(TreeNode* rt, int& sum) {
        if (!rt) return rt;
        if (rt->right) solve(rt->right, sum);
        sum += rt->val;
        rt->val = sum;
        if (rt->left) solve(rt->left, sum);
        return rt;
    }
};