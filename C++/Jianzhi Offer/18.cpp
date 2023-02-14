// 剑指 Offer 18. 删除链表的节点


/*
    双指针，T=O(n)
*/
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *pre = p, *cur = p->next;
        while (cur)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                cur->next = nullptr;
                break;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return p->next;
    }
};