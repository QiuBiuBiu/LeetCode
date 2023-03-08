// 236. 二叉树的最近公共祖先


/*
    递归法
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right) return nullptr;
        if (!right) return left;
        if (!left) return right;
        return root;
    }
};