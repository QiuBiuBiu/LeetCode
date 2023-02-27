// 114. 二叉树展开为链表
// 给你二叉树的根结点 root ，请你将它展开为一个单链表：
// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。


/*
    1）先序遍历+vector记录路径，T=O(n)，S=O(n)
*/
class Solution {
public:
    vector<TreeNode* > path;
    void flatten(TreeNode* root) {
        preorder(root);
        for (int i = 0; i < path.size(); i++)
        {
            path[i]->left = nullptr;
            path[i]->right = i == path.size() - 1 ? nullptr : path[i + 1];
        }
    }
    void preorder(TreeNode* root)
    {
        if (!root) return ;
        path.emplace_back(root);
        preorder(root->left);
        preorder(root->right);
    }
};


/*
    2.1）先序遍历+记录一个当前节点的前序节点，T=O(n)，S=O(n)
    此方法有些类似98题，只不过一个是先序遍历，一个是中序遍历
*/
class Solution {
public:
    TreeNode* pre;
    void flatten(TreeNode* root) {
        preorder(root);
    }
    void preorder(TreeNode* root)
    {
        if (!root) return ;
        if (pre) // 用当前节点更新前序节点的左右子树
        {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root; // 为下一个节点更新前序节点
        TreeNode* tmp = root->right; // [*] 假如递归遍历到第二个节点，上面的if语句中会修改第一个节点的右指针为root，为了等第一个节点的左子树遍历完成后，顺利遍历右子树，需要在此时用一个临时变量记录root->right
        preorder(root->left);
        preorder(tmp);
    }
};

/*
    2.2) 将2.1中二叉树的先序遍历改为非递归实现，T=O(n)，S=O(n)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode* > sk;
        if (root) sk.push(root);
        TreeNode* pre = nullptr;
        while (!sk.empty())
        {
            auto cur = sk.top();
            if (pre)
            {
                pre->left = nullptr;
                pre->right = cur;
            }
            pre = cur;
            sk.pop(); // 非递归实现就没有递归中需要保存root->right的那一步了，因为root->right早早地放进了栈里
            if (cur->right) sk.push(cur->right);
            if (cur->left) sk.push(cur->left);
        }
    }
};

/*
    3）将二叉树转化成链表进行遍历
    Refer from: https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/356853/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/
    上面两种方法都借助先序遍历，而先序遍历都需要借助栈，如何省掉这个栈呢？
    先序遍历的顺序是：根，左，右。 对当前节点而言：（1）当左子树为空时，不需要对其展开； （2）当左子树不空时，遍历完左子树最右侧的节点后，开始遍历当前节点的右子树。
    因此，当左子树不空时，a)我们需要寻找到左子树的最右侧节点，b)将当前节点的右子树放到这个最右侧节点的右子树下。
    最后，c)我们可以通过不断遍历当前节点的右子树来遍历完整棵树，而不需要借助栈。
    所以，整体的思路就是将将二叉树转化成链表进行遍历。
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        auto cur = root;
        while (cur)
        {
            if (cur->left) // 情形2
            {
                auto pre = cur->left;
                while (pre->right) pre = pre->right; // a)找到左子树的最右侧节点
                pre->right = cur->right; // b)将当前节点的右子树放到这个最右侧节点的右子树下
                // 更新cur的左右指针
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right; // 情形1，或将情形2转化为情形1
        }
    }
};