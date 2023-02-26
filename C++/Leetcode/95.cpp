// 95. 不同的二叉搜索树 II
// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

/*
    递归
    枚举根节点的值为i，那么根据二叉搜索树的性质:
    我们可以知道左子树的节点值的集合为 [1…i−1]，右子树的节点值的集合为 [i+1…n]。
    而左子树和右子树的生成相较于原问题是一个序列长度缩小的子问题，因此我们可以想到用递归的方法来解决这道题目。
*/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
    vector<TreeNode*> generate(int st, int end)
    {
        if (st > end) return vector<TreeNode*>{ nullptr };

        vector<TreeNode*> root;
        for (int i = st; i <= end; i++)
        {
            auto left = generate(st, i - 1);
            auto right = generate(i + 1, end);

            for (const auto& le : left)
            {
                for (const auto& ri : right)
                {
                    TreeNode* rt = new TreeNode(i);  // 以i作为根节点
                    rt->left = le;
                    rt->right = ri;
                    root.emplace_back(rt);
                }
            }
        }
        return root;
    }
};