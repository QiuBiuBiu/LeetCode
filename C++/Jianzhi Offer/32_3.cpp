// 剑指 Offer 32 - III. 从上到下打印二叉树 III
// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。


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
        int flag = 1; // 用一个flag来记录是否要逆序存储
        while (!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                auto cur = q.front();
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                q.pop();
            }
            if (!flag) reverse(tmp.begin(), tmp.end()); // 反转，或者在for循环的时候倒着存
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};