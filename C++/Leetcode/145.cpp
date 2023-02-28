// 145. 二叉树的后序遍历


/*
    [模版]
    1）先往左遍历并压栈
    2）遍历到最左侧后，检查cur是否无右子树或者cur的右子树就是pre
    3）若是，则说明对cur没有右子树 或者 它的右子树已经遍历完成了，则记录cur->val
    4）若否，则向右移动一步，继续遍历cur的右子树
    5）重复1）2）3）4）
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* pre;
        stack<TreeNode* > sk;
        while (root || !sk.empty())
        {
            while (root) // 1）
            {
                sk.push(root);
                root = root->left;
            }

            auto cur = sk.top(); // 2）
            if (!cur->right || cur->right == pre) // 3）
            {
                res.emplace_back(cur->val);
                pre = cur;
                root = nullptr;
                sk.pop();
            }
            else // 4）
            {
                root = cur->right;
            }
        }
        return res;
    }
};


/*
    此中解法和144题先序遍历的代码类似
    即，将先序遍历的遍历方向交换；
    最后reverse数组中的序列即为后续遍历的结果。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* pre;
        stack<TreeNode* > sk;
        while (root || !sk.empty())
        {
            while (root)
            {
                sk.push(root);
                res.emplace_back(root->val);
                root = root->right;
            }
            auto cur = sk.top();
            sk.pop();
            if (cur->left) root = cur->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};