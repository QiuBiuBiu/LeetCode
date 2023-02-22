// 剑指 Offer 54. 二叉搜索树的第k大节点

/*
    1）中序遍历整个二叉搜索树，T=O(n)
*/
class Solution {
public:
    vector<int> res; // 用数组来保存整个序列
    int kthLargest(TreeNode* root, int k) {
        get(root);
        return res[res.size() - k]; // 最终倒数第k个树即为所求
    }
    void get(TreeNode* rt)
    {
        if (!rt) return;

        if (rt->left) get(rt->left);
        res.push_back(rt->val);
        if (rt->right) get(rt->right);
    }
};

/*
    2）中序遍历，提前返回，最差情况：T(n)=O(n)
*/
class Solution {
public:
    int res;
    int kthLargest(TreeNode* root, int k) {
        get(root, k);
        return res;
    }
    void get(TreeNode* root, int& k)  // 注意这里必须是k的引用，或者可以把k设置为成员变量
    {
        if (k <= 0) return; // 提前返回
        if (root->right) get(root->right, k);
        if (--k == 0) // 提前返回
        {
            res = root->val;
            return;
        }
        if (root->left) get(root->left, k);
    }
};