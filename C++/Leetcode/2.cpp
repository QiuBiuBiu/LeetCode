/*
2. 两数相加
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    请你将两个数相加，并以相同形式返回一个表示和的链表。
    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    输入：l1 = [2,4,3], l2 = [5,6,4]
    输出：[7,0,8]
    解释：342 + 465 = 807.
*/

/*
    链表遍历，T=O(n), S=O(n)
    题目中链表记录数字的是倒序的，我们正好可以利用特征从两个链表的个位开始做加法，同时用一个carry来记录进位。
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            if (l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry % 10); // 新节点
            p = p->next;
            carry /= 10;
        }
        return dummy->next;
    }
};