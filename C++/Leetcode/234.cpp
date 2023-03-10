// 234. 回文链表


/*
    1）栈，T=O(n), S=O(n)
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> sk;
        ListNode* p = head;
        while (p)
        {
            sk.push(p);
            p = p->next;
        }

        p = head;
        while (!sk.empty() && sk.top() != p)
        {
            if (p->val != sk.top()->val) return false;
            p = p->next;
            sk.pop();
        }
        return true;
    }
};

/*
    2）递归，T=O(n), S=O(n)
*/
class Solution {
public:
    ListNode *front = nullptr;
    bool isPalindrome(ListNode* head) {
        front = head;
        return check(head);
    }
    bool check(ListNode* head)
    {
        if (!head) return true;

        if (!check(head->next)) return false;

        if (head->val != front->val) return false;

        front = front->next;

        return true;
    }
};


/*
    3）三步法，T=O(n), S=O(1)
        1）拿到中间节点(leetcode 876)
        2）翻转第二段链表(leetcode 226)
        3）两个链表从前至后进行比较
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* middle = getMiddleNode(head);         // 1）
        ListNode* rightHead = reverse(middle->next);    // 2）
        while (head && rightHead)                       // 3）
        {
            if (head->val != rightHead->val) return false;
            head = head->next;
            rightHead = rightHead->next;
        }
        return true;
    }
    ListNode* getMiddleNode(ListNode* head)
    {
        ListNode *p = head, *q = head;
        while (p && p->next)
        {
            p = p->next->next;
            if (!p) return q;   // 这里跟leetcode 876稍有区别，当链表为偶数个节点时。比如长度为2的情况，我们应该希望返回第1个，而不是第2个
            q = q->next;
        }
        return q;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode *pre = nullptr, *cur = head;
        while (cur)
        {
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};