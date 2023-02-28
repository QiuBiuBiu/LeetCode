// 94. 二叉树的中序遍历

/*
    [模版]和144前序遍历的模版类似，只是记录的位置稍有区别
    1）先往左遍历并压栈
    2）遍历到最左侧后，停下来并记录cur->val，往右移动一格
    3）重复1）2）
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > sk;
        while (root || !sk.empty())
        {
            while (root)
            {
                sk.push(root);
                root = root->left;
            }
            auto cur = sk.top();
            sk.pop();
            res.emplace_back(cur->val); // 左子树遍历完成了，于是cur即为中序遍历的第一个节点
            root = cur->right;
        }
        return res;
    }
};