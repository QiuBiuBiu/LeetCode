// 21. 合并两个有序链表
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


/*
    遍历+指针修改，T=O(n+m)
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode *p1 = list1, *p2 = list2, *p = head;
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