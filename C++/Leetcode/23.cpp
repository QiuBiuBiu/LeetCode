// 23. 合并K个升序链表
// 给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。


/*
    1）分治法，T=O(knlogk)，S=O(logk)
    由21题已知合并两个升序链表的方法，配合分治法我们可以解决合并K个升序链表的问题
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int a, int b)
    {
        int m = (a + b) / 2;
        if (a > b) return nullptr;
        if (a == b) return lists[a];
        if (a + 1 == b) return merge2Lists(lists[a], lists[b]);
        return merge2Lists(merge(lists, a, m), merge(lists, m + 1, b));
    }
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        ListNode *head = new ListNode(-1), *p = head;
        ListNode *p1 = list1, *p2 = list2;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else 
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        
        if (p1 && !p2) p->next = p1;
        if (!p1 && p2) p->next = p2;
        return head->next;
    }
};