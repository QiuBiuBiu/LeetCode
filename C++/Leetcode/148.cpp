// 148. 排序链表


/*
    归并排序，T=O(nlogn), S=O(n)
        1）找到链表中间节点(leetcode 876)，将链表分成左右两段
        2）递归地将左右两段排序
        3）合并左右两段已经排好序的链表(leetcode 21)
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *middleNode = getMiddleNode(head);
        ListNode *rightHead = middleNode->next;
        middleNode->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return merge(left, right);
    }
    ListNode* getMiddleNode(ListNode* head)
    {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            if (!p) return q;   // 这里跟leetcode 876稍有区别，当链表为偶数个节点时。比如长度为2的情况，我们应该希望返回第1个，而不是第2个
            q = q->next;        // 否则，归并排序会在两节点的情况下死循环。
        }
        return q;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if (!left && !right) return nullptr;
        if (!left) return right;
        if (!right) return left;

        ListNode *head = new ListNode(-1), *p = head; // 借助一个dummy节点，更容易写merge
        while (left && right)
        {
            if (left->val < right->val)
            {
                p->next = left;
                p = left;
                left = left->next;
            }
            else
            {
                p->next = right;
                p = right;
                right = right->next;
                
            }
        }

        if (left) p->next = left;
        else if (right) p->next = right;

        return head->next;
    }
};