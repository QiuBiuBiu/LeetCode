/*
337. 打家劫舍 III
    小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
    除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
    给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

    输入: root = [3,2,3,null,3,null,1]
    输出: 7 
    解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
*/

/*
    1）dp，递归法，T=O(n)，S=O(n)
   题198的升级，我们用一个map来记录这个root有没有被计算过。
*/
class Solution {
public:
    int rob(TreeNode* root) {
        map<TreeNode*, int> f;
        return dp(root, f);
    }
    int dp(TreeNode* root, map<TreeNode*, int>& f)
    {
        if (!root) return 0;
        if (f.find(root) != f.end()) return f[root];

        int robIncludeRT = root->val + 
                           (root->left ? (dp(root->left->left, f) + dp(root->left->right, f)) : 0) + 
                           (root->right ? (dp(root->right->left, f) + dp(root->right->right, f)) : 0);
        //int robIncludeRT = root->val;
        // if (root->left)
        // {
        //     cout << "left" << endl;
        //     robIncludeRT += dp(root->left->left, f) + dp(root->left->right, f);
        // }
        // if (root->right)
        // {
        //     cout << "right" << endl;
        //     robIncludeRT += dp(root->right->left, f) + dp(root->right->right, f);
        // }
        int robExcludeRT = dp(root->left, f) + dp(root->right, f);
        int robMax = max(robIncludeRT, robExcludeRT);
        f[root] = robMax;
        return robMax;
    }
};

/*
    2）性能更优的办法：
    https://leetcode.cn/problems/house-robber-iii/solutions/266960/shu-xing-dp-ru-men-wen-ti-by-liweiwei1419/
*/