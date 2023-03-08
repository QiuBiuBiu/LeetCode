// 543. 二叉树的直径
// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。


/*
    后序遍历
    后序遍历每个节点，计算以该点为直径交点的直径长度。
    注意：直径可能穿过也可能不穿过根结点。
*/
class Solution {
public:
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findDiameter(root, nullptr);
        return res;
    }
    int findDiameter(TreeNode* root, TreeNode* pre)
    {
        if (!root) return 0;

        int left = 0;
        if (root->left) left = 1 + findDiameter(root->left, root);

        int right = 0; 
        if (root->right) right = 1 + findDiameter(root->right, root);

        res = max(res, left + right);

        return max(left, right);
    }
};