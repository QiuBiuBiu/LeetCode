// 146. LRU 缓存
// 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。


/*
    哈希+双向链表
*/
class LRUCache {
private:
    struct node {
        node *left = NULL;
        node *right = NULL;
        int key, val;
        node(int Key, int Val) : left(NULL), right(NULL), key(Key), val(Val) {};
    };
public:
    unordered_map<int, node*> mp;
    node *dummyHead = NULL; // 虚拟头节点
    node *dummyTail = NULL; // 虚拟尾节点
    int size;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        dummyHead = new node(-1, -1);
        dummyTail = new node(-1, -1);

        // 初始化时将头尾连接起来
        dummyHead->right = dummyTail; 
        dummyTail->left = dummyHead;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end())
        {
            int val = mp[key]->val;
            erase(mp[key]); // 利用map来定位，删除节点
            mp[key] = insertFront(key, val); // 然后将该节点插入队头，并更新map中的node指针
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end())
        {
            erase(mp[key]); // 如果能找到的话要更新value，这里跟get的逻辑一致
        }
        else
        {
            if (size == capacity) // 没找到的话要先查看size
            {
                mp.erase(dummyTail->left->key); // 没有空间了，先利用队尾指针来更新map
                removeBack(); // 然后把队尾删除
            }
            else
            {
                ++size; // 还有空间则更新size
            }
        }
        mp[key] = insertFront(key, value); // 最终都要将新节点移至队头，并更新map
    }

private:
    node* insertFront(int key, int val) // 插入操作需要返回值，以便更新map
    {
        node *tmp = new node(key, val);
        tmp->right = dummyHead->right;
        tmp->left = dummyHead;
        dummyHead->right->left = tmp;
        dummyHead->right = tmp;
        return tmp;
    }
    void removeBack()
    {
        node *tmp = dummyTail->left;
        dummyTail->left = tmp->left;
        tmp->left->right = dummyTail;
        delete tmp;
    }
    void erase(node* cur)
    {
        node *pre = cur->left;
        node *nex = cur->right;
        pre->right = nex;
        nex->left = pre;
        delete cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */