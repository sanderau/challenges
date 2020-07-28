

#list node
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

	def len(self) -> int:
		l = 0
		ptr = self
		
		while(ptr != None):
			l += 1
			ptr = ptr.next

		return l

class Solution:
	def addTwoNumber(self, l1: ListNode, l2: ListNode) -> ListNode:
		head = ListNode()
		ptr = head

		if( l1.len() > l2.len() ):
			head.val = l1.val
			l1 = l1.next

			# first list is longer, so add l1 to solution until they are even
			while(l1.len() > l2.len()):
				toAdd = ListNode(l1.val)
				ptr.next = toAdd
				ptr = ptr.next
				l1 = l1.next

		elif( l1.len() < l2.len() ):
			# second is longer, add to solution until even.
			head.val = l2.val
			l2 = l2.next

			while(l2.len() > l1.len()):
				toAdd = ListNode(l2.val)
				ptr.next = toAdd
				ptr = ptr.next
				l2 = l2.next

		# at this point we can assume they are the same lenght, so continue as normal
		overflow = False

		if( head.val == 0 and head.next == None ):
			# head has not been initialized
			s = l1.val + l2.val

			if( s >= 10):
				s -= 10
				overflow = True

			head.val = s
			l1 = l1.next
			l2 = l2.next

		while( l1 != None and l2 != None ):
			s = l1.val + l2.val
			
			if( overflow ):
				overflow = False
				s += 1

			if( s >= 10 ):
				overflow = True
				s -= 10

			ptr.next = ListNode(s)
			ptr = ptr.next

			l1 = l1.next
			l2 = l2.next
				

	
		return head


def arrToListNode(arr) -> ListNode:
	head = ListNode(arr[0])
	ptr = head
	length = len(arr)

	for i in range(1, length):
		toAdd = ListNode(arr[i])
		ptr.next = toAdd
		ptr = ptr.next
		

	return head

def printListNode(ln: ListNode):
	
	while( ln != None):
		print(ln.val)
		ln = ln.next

def main():
	sol = Solution()
	l1 = arrToListNode( [2,4,3] )
	l2 = arrToListNode( [5,6,4] )

	l3 = sol.addTwoNumber(l1, l2)

	printListNode(l3)


main()
