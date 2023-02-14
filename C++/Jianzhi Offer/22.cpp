// 剑指 Offer 22. 链表中倒数第k个节点


/*
    双指针，T=O(n)
    快指针先移动k步，然后快慢指针一起移动知道快指针到达链表尾端
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p1 = dummy, *p2 = dummy;
        while (k--) p1 = p1->next;
        while (p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};