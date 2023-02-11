/*
86. 分隔链表
    给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
    你应当 保留 两个分区中每个节点的初始相对位置。
*/


/*
    维护两个链表，T=O(n)，S=O(1)
    一个用来存储小于x的节点，一个用来存储大于x的节点，最后将两个链表连起来即可。
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* p = head, *p1 = dummy1, *p2 = dummy2;
        while (p)
        {
            if (p->val < x)
            {
                p1->next = p;
                p1 = p1->next;
            }
            else
            {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = dummy2->next;
        p2->next = nullptr;
        return dummy1->next;
    }
};