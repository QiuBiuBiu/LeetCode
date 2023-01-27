// 剑指 Offer 33. 二叉搜索树的后序遍历序列

/*
    递归分治法，T=O(n^2), S=O(n)
    后序遍历序列的根节点由后向前推，而由二叉搜索树的性质，我们可以把二叉搜索树分成两部分：
    一部分是左子树的节点，它们都比根节点的值要小；
    另一部分是右子树的节点，它们都比根节点的值要大；
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }
    bool verify(vector<int>& order, int st, int end)
    {
        if (st >= end) return true;

        int k = st;
        while (k < end && order[k] < order[end]) k++;
        int pos = k;
        while (k < end && order[k] > order[end]) k++;

        // 这里的k == end的判断尤为重要，验证了上面说到的二叉搜索树后序遍历的性质，当前满足这个条件后，再递归地判断左右子树
        return k == end && verify(order, st, pos - 1) && verify(order, pos, end - 1);
    }
};

/*
    Todo：单调栈解法，T=O(n), S=O(n)
*/
