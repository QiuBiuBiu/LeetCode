// 24. 两两交换链表中的节点


/*
    递归法
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* nex = head->next;

        head->next = swapPairs(head->next->next);
        nex->next = head;

        return nex;
    }
};


/*
    迭代法（Todo: 待优化）
	交换头两个节点后，链表的头节点发生了变化，这里用first作为标记。
	同时，对于其后的两两节点，交换了p->next，q->next的顺序后，还应该使p节点之前的节点t: t->next = q.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head, *q, *t;
        int first = 1;
        while (p && (q = p->next)) {
            p->next = q->next;
            q->next = p;                

            if (first) {
                head = q;
                first = 0;
            }
            else {
                t->next = q;
            }
            t = p;
            p = p->next;
        }
        return head;
    }
};