# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l, tot, flag = ListNode(0), 0, 1
        L = l
        while l1 or l2:
            if l1:
                tot += l1.val
                l1 = l1.next
            if l2:
                tot += l2.val
                l2 = l2.next

            tot, val = divmod(tot, 10)
            l.next = ListNode(val)
            l = l.next

        if tot:
            l.next = ListNode(tot)

        return L.next