// 剑指 Offer 37. 序列化二叉树

/*
    先序遍历 + 空节点标记，T=O(n), S=O(n)
    (PS：7.cpp中介绍了根据先序序列和中序序列来重建二叉树的方法，但是此方法有一个限制是：二叉树中不能有重复数值的节点。所以这道题不能用此方法)
    先序序列中，第一个节点即为根节点，我们借助这个性质 + 用特殊字符来标记空节点 来完成序列化和反序列化的过程

*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // 先序遍历来序列化二叉树
        if (!root) return "#,"; // 用#来标记空节点

        string str = to_string(root->val) + ",";

        str += serialize(root->left);
        str += serialize(root->right);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        list<string> tree; // 用一个list来存储树中的所有节点，使得建树的代码变得更容易，这点非常重要
        int k = 0;
        while (k < data.size())
        {
            string tmp = "";
            while (k < data.size() && data[k] != ',') // 根据分隔符“，”来取出所有节点
            {
                tmp += data[k];
                k++;
            }
            tree.push_back(tmp);
            k++;
        }

        return buildTree(tree); // 用list来辅助建树
    }
    TreeNode* buildTree(list<string>& tree)
    {
        if (tree.front() == "#")
        {
            tree.erase(tree.begin()); // 完成一个节点后，要更新list。由于有频繁的erase操作，所以我们优先使用list而不是vector
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(tree.front())); // stoi方法将string转换成int
        tree.erase(tree.begin()); // 完成一个节点后，要更新list

        root->left = buildTree(tree);
        root->right = buildTree(tree);

        return root;
    }
};

/*
    用istringstream和ostringstream来代替list，实现要更加容易，但代码思路是一样的
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        _serialize(root, out);
        return out.str();
    }

    void _serialize(TreeNode* root, ostringstream& out)
    {
        if (root)
        {
            out << to_string(root->val) << " "; // 注意这里的空格，否则从istringstream每次取出的string就不是单个单个的
            _serialize(root->left, out);
            _serialize(root->right, out);
        }
        else
        {
            out << "# "; // 注意这里的空格
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return _deserialize(in);
    }
    TreeNode* _deserialize(istringstream& in)
    {
        string str;
        in >> str;

        if (str == "#")
        {
            return nullptr;
        }
        else
        {
            cout << str << endl;
            TreeNode* root = new TreeNode(stoi(str));

            root->left = _deserialize(in);
            root->right = _deserialize(in);

            return root;
        }
    }
};