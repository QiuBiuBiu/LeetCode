// 剑指 Offer 35. 复杂链表的复制
// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

/*
    1）借助map保存 复制链表 和 被复制链表 的映射关系， T=O(n)，S=O(n)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *clone = new Node(-1);
        Node *p1 = head, *p2 = clone;
        map<Node*, Node*> mp;
        while (p1) // 第一次遍历，复制除random指针外的内容
        {
            Node *cur = new Node(p1->val);
            p2->next = cur;
            mp.insert({p1, cur}); // 用map来保存 复制链表 和 被复制链表 的映射关系
            p1 = p1->next;
            p2 = p2->next;
        }

        p1 = head, p2 = clone->next; 
        while (p1) // 第二次遍历，借助map来复制random指针
        {
            p2->random = mp[p1->random];
            p2 = p2->next;
            p1 = p1->next;
        }
        return clone->next;
    }
};

/*
    2）三步法，T=O(n)，S=O(1)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 第一步，复制整个链表所有节点除random指针外的内容，并将 复制的节点 插入 被复制节点的后面
        Node *p = head;
        while (p)
        {
            Node *clone = new Node(p->val);
            clone->next = p->next;
            p->next = clone;

            p = clone->next;
        }

        // 第二步，复制random节点，复制节点的random指针 指向 被复制节点的random节点的后一个节点/或者是nullptr
        p = head;
        while (p)
        {
            Node *clone = p->next;
            if (p->random)
                clone->random = p->random->next; // 复制节点的random指针

            p = clone->next;
        }

        // 第三步，将整个链表拆分成两个，返回我们复制的那个
        Node *cloneHead = new Node(-1);
        cloneHead->next = head->next;
        Node *q = head->next;
        p = head;
        while (p)
        {
            p->next = q->next;
            p = p->next;
            if (p) // 为空的话说明已经到了链表尾端了
            {
                q->next = p->next;
                q = q->next;
            }
        }
        return cloneHead->next;
    }
};