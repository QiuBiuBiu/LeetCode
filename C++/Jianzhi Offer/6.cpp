// 剑指 Offer 06. 从尾到头打印链表

/*
    1）递归
*/
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        recur(head);
        return res;
    }
    void recur(ListNode* p)
    {
        if (!p) return;
        recur(p->next);
        res.emplace_back(p->val);
    }
};

/*
    2）栈
*/
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> sk;
        auto p = head;
        while (p)
        {
            sk.push(p->val);
            p = p->next;
        }
        vector<int> res;
        while (!sk.empty())
        {
            res.push_back(sk.top());
            sk.pop();
        }
        return res;
    }
};