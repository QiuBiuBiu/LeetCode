// 101. 对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

/*
    二叉树的先序遍历，T=O(n)
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check(root->left, root->right);
    }
    bool check(TreeNode* rt1, TreeNode* rt2)
    {
        if (!rt1 && !rt2) return true;
        if (!rt1 || !rt2) return false;
        if (rt1->val == rt2->val)
        {
            return check(rt1->left, rt2->right) && check(rt1->right, rt2->left);
        }
        return false;
    }
};