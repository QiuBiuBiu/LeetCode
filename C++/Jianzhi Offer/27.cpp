// 剑指 Offer 27. 二叉树的镜像


/*
    递归回溯法（二叉树的先序遍历）
*/
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        return swapTree(root);
    }
    TreeNode* swapTree(TreeNode* p)
    {
        if (!p) return nullptr;
        swap(p->left, p->right);
        swapTree(p->left);
        swapTree(p->right);
        return p;
    }
};