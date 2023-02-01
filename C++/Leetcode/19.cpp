/*
思路：维护两个距离相差为n+1的指针
    （ps:由于是无头节点的链表，则删除第一个节点的操作和删除其他节点的操作会有区别）
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        int k = 0;
        while(p) {
            p = p->next;
            if(k == n + 1) 
                q = q->next;
            else
                k++;
        }
        if(k == n)  //找不到删除节点的前序节点，即为要删除第一个节点
            head = head->next;
        else  //删除其他节点
            q->next = q->next->next;
        return head;
    }
};