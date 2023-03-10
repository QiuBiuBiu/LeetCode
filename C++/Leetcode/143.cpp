// 143. 重排链表


/*
    1）辅助线性表，T=O(n), S=O(n)
    借助一个线性表使得以O(1)的时间取到头尾节点。
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode *p = head;
        while (p)
        {
            nodes.emplace_back(p);
            p = p->next;
        }

        int i = 0, j = nodes.size() - 1;
        while (i < j - 1)
        {
            nodes[i]->next = nodes[j];
            nodes[j]->next = nodes[i + 1];
            ++i, --j;
        }
        nodes[j]->next = nullptr;

    }
};


/*
    2）三步法，T=O(n), S=O(1)
        1）拿到中间节点，leetcode 876
        2）将链表分成两段，把后一段翻转，leetcode 226
        3）将两段链表交错合并
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *middleNode = getMiddleNode(head);

        ListNode* secHead = reverse(middleNode->next);
        middleNode->next = nullptr;

        merge(head, secHead);
    }
    ListNode* getMiddleNode(ListNode* head)
    {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
        }
        return q;
    }
    ListNode* reverse(ListNode* head)
    {
        if (!head || !head->next) 
            return head;
        ListNode *last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    void merge(ListNode* p, ListNode* q)
    {
        while (p && q)
        {
            ListNode* tmpP = p->next;
            ListNode* tmpQ = q->next;

            p->next = q;
            p = tmpP;

            q->next = p;
            q = tmpQ;
        }
    }
};