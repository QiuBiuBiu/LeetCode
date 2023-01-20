// 剑指 Offer 55 - I. 二叉树的深度

/*
    1）dfs(后序遍历), T=O(n), n为节点数
    用Max来记录树的深度，到每个叶子结点时尝试更新Max的值
*/
class Solution {
public:
    int Max;
    int maxDepth(TreeNode* root) {
        Max = 0;
        dfs(root, 1);
        return Max;
    }
    void dfs(TreeNode* rt, int depth)
    {
        if (!rt) return;
        if (!rt->left && !rt->right) // 叶子节点
        {
            Max = max(Max, depth);
            return;
        }
        dfs(rt->left, depth + 1);
        dfs(rt->right, depth + 1);
    }
};

/*
    2）递归算法, T=O(n)
    当前树的最大的深度=左右子树最大深度的较大值 + 1
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
    3）bfs(层序遍历), T=O(n), n为节点数
*/