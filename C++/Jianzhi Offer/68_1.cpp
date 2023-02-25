// 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

/*
    递归法，T=O(n)
    本题给了两个重要条件，1）树是二叉搜索树 2）所有节点的值都是唯一的，所以有：
    1）root节点比两个数都大，那么答案在它的左子树中
    2）root节点比两个数都小，那么答案在它的右子树中
    3）root大于一个且小于另一个，那么最近公共祖先就是root

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) return nullptr;

        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else if (root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);

        else return root;
    }
};