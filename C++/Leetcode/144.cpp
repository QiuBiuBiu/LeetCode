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

/*
    [模版]
    1）先往左遍历并压栈，并记录root->val
    2）遍历到最左侧后，停下来，往右移动一格
    3）重复1）2）
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > sk;
        while (root || !sk.empty())
        {
            while (root)
            {
                sk.push(root);
                res.emplace_back(root->val);
                root = root->left;
            }
            auto cur = sk.top(); // while(root)执行结束后，相当于把cur的左子树已经遍历完了，从栈里取出cur，我们尝试遍历它的右子树
            sk.pop();
            root = cur->right;
        }
        return res;
    }
};