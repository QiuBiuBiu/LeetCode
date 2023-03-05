// 92. 反转链表 II


/*
    递归法
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) // 当left为1时，问题转化为翻转前right个节点的问题
        {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1); // 递归
        return head;
    }
    ListNode* reverseN(ListNode* cur, int k) // 返回值为翻转后的头节点
    {
        ListNode* pre = nullptr, *rear = cur;
        while (k--)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;            
        }
        rear->next = cur; // 翻转后要记得修改尾节点的next指针
        return pre;
    }
};