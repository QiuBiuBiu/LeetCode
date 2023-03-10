// 876. 链表的中间结点


/*
    1）两次遍历，一次求链表长度，一次招中间节点
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while (p)
        {
            ++len;
            p = p->next;
        }

        p = head;
        len = len / 2;
        while (len--)
        {
            p = p->next;
        }
        return p;
    }
};

/*
    2）双指针
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            q = q->next;
        }
        return q;
    }
};
