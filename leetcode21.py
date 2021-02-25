class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = None
        pointer = head
        count = 0
        while (not (l1 is None or l2 is None)):
            selected = None
            if (l1.val < l2.val):
                selected = l1
                l1 = l1.next
            else:
                selected = l2
                l2 = l2.next
            if (count == 0):
                head = selected
                pointer = head
                count = 1
            else:
                pointer.next = selected
                pointer = selected
        if (l1 is None):
            pointer.next = l2
        else:
            pointer.next = l1
        return head