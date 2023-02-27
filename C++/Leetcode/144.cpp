// 144. 二叉树的前序遍历

/*
    （非递归实现）栈，T=O(n)，S=O(n)
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > sk;
        if (root) sk.push(root);
        while (!sk.empty())
        {
            auto cur = sk.top();
            res.emplace_back(cur->val);
            sk.pop();
            if (cur->right) sk.push(cur->right);
            if (cur->left) sk.push(cur->left);
        }
        return res;
    }
};