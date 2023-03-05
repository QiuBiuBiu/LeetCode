// 25. K 个一组翻转链表


/*
    递归
*/
class Solution {
public:
    // 返回值为翻转后的头节点
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr; // 递归终止条件1：每段都已翻转完了

        ListNode *a = head, *b = head;
        for (int i = 0; i < k; ++i)
        {
            if (!b) return head; // 递归终止条件2：最后一段不足k个节点，直接返回其head
            b = b->next;
        }

        ListNode *newHead = reverseBetween(a, b); // 1）把第一段的k个节点翻转完成，得到新的头节点newHead，a即head翻转后变成了第一段的尾节点，b为第二段的头节点

        a->next = reverseKGroup(b, k); // 2）开始递归，翻转下一段的k个节点
        return newHead;
    }
    ListNode* reverseBetween(ListNode* cur, ListNode* end) // 翻转[a,b)之间的链表
    {
        ListNode* pre = end;
        while (cur != end)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;            
        }
        return pre;
    }
};