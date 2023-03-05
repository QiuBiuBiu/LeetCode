// 206. 反转链表
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


/*
    1）迭代法
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode* nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};

/*
    2）递归法
    先将第一个节点翻转，然后递归翻转后面的节点
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
    ListNode* reverse(ListNode* cur, ListNode* pre)
    {
        if (!cur) return pre;

        ListNode* nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;

        return reverse(cur, pre);
    }
};


/*
    3）递归法
    先翻转后面的节点，最后翻转第一个节点
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
