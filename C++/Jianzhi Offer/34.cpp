// 剑指 Offer 34. 二叉树中和为某一值的路径

/*
    回溯法(先序遍历)，T=O(n)
*/

class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return vector<vector<int>>{};
        vector<int> path;
        find(root, path, root->val, target);
        return paths;
    }
    void find(TreeNode* root, vector<int>& path, int total, int target)
    {
        path.push_back(root->val); //记录路径
        if (!root->left && !root->right && total == target) 
        {
            paths.push_back(path);
            path.pop_back(); // 回溯
            return;
        }
        
        if (root->left) find(root->left, path, total + root->left->val, target);
        if (root->right) find(root->right, path, total + root->right->val, target);

        path.pop_back(); // 回溯
    }
};