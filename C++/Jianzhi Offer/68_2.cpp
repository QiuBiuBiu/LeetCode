// 剑指 Offer 68 - II. 二叉树的最近公共祖先


/*
    二叉树的后续遍历，T=O(n)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto leftRes = lowestCommonAncestor(root->left, p, q);
        auto rightRes = lowestCommonAncestor(root->right, p, q);
        if (!leftRes && !rightRes) return nullptr;
        if (!leftRes) return rightRes;
        if (!rightRes) return leftRes; 
        return root;
    }
};