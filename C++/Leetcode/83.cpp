/*
83. 删除排序链表中的重复元素
    给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。

    输入：head = [1,1,2]
    输出：[1,2]
*/


/*
    双指针，T=O(n)，S=O(1)
    这题是26.cpp对应的链表题
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy->next, *q = dummy->next;
        while (q)
        {
            if (p->val != q->val)
            {
                p->next = q;
                p = q;
            }
            q = q->next;
        }
        if (p != q) p->next = q; 
        return dummy->next;
    }
};