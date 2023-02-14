// 剑指 Offer 52. 两个链表的第一个公共节点


/*
    1）计算两个链表的长度然后做差，即可将问题转化为 22. 链表中倒数第k个节点
*/


/*
    2）双指针，T=O(n), S=O(1)
    两个指针(p和q)分别从链表A和链表B的头开始同时遍历；
    当它们遍历到链表尾部时，p从链表B的头接着遍历，而q从链表A的头接着遍历；
    当p和q相遇时，即为相交节点。
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        auto p = headA, q = headB;
        int flag = 0;
        while (p != q)
        {
            
            if (!p->next) flag++;
            if (flag > 1) return nullptr; // 当p或q遍历完A和B还没相遇，则两个链表没有交点
            p = !p->next ? headB : p->next;
            q = !q->next ? headA : q->next;
        }
        return p;
    }
};