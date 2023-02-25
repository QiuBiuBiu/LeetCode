// 98. 验证二叉搜索树
// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。


/*
    中序遍历，T=O(n)，S=O(n)
    维护当前节点的前一个节点，（因为val取值范围的问题需要初始化为最小的long long）
    然后进行中序遍历和pre进行比较，
*/
class Solution {
public:
    long long pre = LLONG_MIN; // 初始化
    bool isValidBST(TreeNode* root) {

        if (!root) return true;

        if (!isValidBST(root->left)) return false;

        if (root->val <= pre) return false;
        pre = root->val;

        return isValidBST(root->right);
    }
};
