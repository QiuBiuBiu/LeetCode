// 剑指 Offer 28. 对称的二叉树
// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

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