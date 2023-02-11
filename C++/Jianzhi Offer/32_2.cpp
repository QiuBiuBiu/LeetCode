// 剑指 Offer 32 - II. 从上到下打印二叉树 II
// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。


/*
    二叉树的层次遍历
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> tmp; // 保存每一层的元素
            for (int i = 0; i < n; i++)
            {
                auto cur = q.front();
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                q.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};