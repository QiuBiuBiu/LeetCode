class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode L(0);
        ListNode *r = &L;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                r->next = l1;
                l1 = l1->next;
            }
            else {
                r->next = l2;
                l2 = l2->next;
            }
            r = r->next;
        }
        r->next = l1 ? l1 : l2;
        return L.next;
    }
};