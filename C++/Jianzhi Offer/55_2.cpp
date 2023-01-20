// 剑指 Offer 55 - II. 平衡二叉树

/*
    1）dfs(先序遍历)+判断深度，T=O(nlogn)，自顶向下
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) <= 1) 
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
    int getDepth(TreeNode* rt)
    {
        if (!rt) return 0;
        return max(getDepth(rt->left), getDepth(rt->right)) + 1;
    }
};

/*
    Todo: 
    2）dfs(后序遍历)，T=O(n)，自底向上
*/