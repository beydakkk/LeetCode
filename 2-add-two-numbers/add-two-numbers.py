# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# python solution
class Solution:
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        curr = head
        carry = 0
        while l1 != None or l2 != None or carry != 0:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            sum = val1 + val2 + carry
            carry = sum // 10
            tmp = ListNode(sum%10)
            curr.next = tmp
            curr = tmp
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        head = head.next
        return head