// 剑指 Offer 32 - I. 从上到下打印二叉树
// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。


/*
    二叉树的层次遍历
*/
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty())
        {
            auto tmp = q.front();
            res.push_back(tmp->val);
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            q.pop();  
        }
        return res;
    }
};