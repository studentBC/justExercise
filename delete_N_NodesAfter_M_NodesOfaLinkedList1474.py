#You are given the head of a linked list and two integers m and n.
#
#Traverse the linked list and remove some nodes in the following way:
#
#Start with the head as the current node.
#Keep the first m nodes starting with the current node.
#Remove the next n nodes
#Keep repeating steps 2 and 3 until you reach the end of the list.
#Return the head of the modified list after removing the mentioned nodes.
#
## Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: ListNode, m: int, n: int) -> ListNode:
        ptr = head
        while ptr!=None:
            for i in range(m-1):
                if ptr is None:
                    break
                ptr = ptr.next
            if ptr is not None:
                pt = ptr.next
            else:
                break
            for j in range(n):
                if pt is None:
                    break
                pt = pt.next
            if ptr is not None:
                #print(ptr.val, pt.val)
                ptr.next = pt
                ptr = ptr.next
            else:
                break
            
        return head
