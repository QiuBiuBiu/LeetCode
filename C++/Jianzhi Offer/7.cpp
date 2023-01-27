// 剑指 Offer 07. 重建二叉树

/*
    递归分治法
    先序遍历序列，可以从前往后推出根节点
    中序遍历序列，可以结合根节点，找出左右子树节点
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTr(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTr(vector<int>::iterator preSt, vector<int>::iterator preEnd, vector<int>::iterator inSt, vector<int>::iterator inEnd)
    {
        if (preSt == preEnd) return nullptr;
        TreeNode* root = new TreeNode(*preSt); // 1）先序序列的首项为当前子树的根节点

        auto tmpIt = inSt;
        while (inSt != inEnd && (*inSt) != root->val) inSt++; // 2）找到中序序列中的根节点，得到左右子树的节点个数，从而反推出先序序列中的左右子树分界点
        int n = inSt - tmpIt;

        if (inSt == inEnd) return nullptr;
        
        if (n > 0) root->left = buildTr(preSt + 1, preSt + n + 1, tmpIt, inSt); // 3）[preSt + 1, preSt + n + 1)为先序序列中的左子树节点; [tmpIt, inSt)为中序序列中的左子树节点，这是由2）中推算出来的
        if (inEnd - inSt > 0) root->right = buildTr(preSt + n + 1, preEnd, inSt + 1, inEnd);

        return root;
    }
};