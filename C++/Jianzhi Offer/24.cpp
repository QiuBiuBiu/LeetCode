// 剑指 Offer 24. 反转链表

/*
    维护前，中，后三个指针来完成反转
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *pre = nullptr, *p = head, *nex = head->next;
        while (nex)
        {
            p->next = pre;
            pre = p;
            p = nex;
            nex = p->next;
        }
        if (!nex) p->next = pre;
        return p;
    }
};