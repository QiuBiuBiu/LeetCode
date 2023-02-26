// 102. 二叉树的层序遍历

/*
    bfs
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> res;
        if (root) q.push(root);
        while (!q.empty())
        {
            vector<int> nodes;
            int n = q.size(); // 获得当前层的节点个数
            for (int i = 0; i < n; i++)
            {
                auto tmp = q.front();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                nodes.emplace_back(tmp->val);
                q.pop();
            }
            res.emplace_back(nodes);
        }
        return res;
    }
};