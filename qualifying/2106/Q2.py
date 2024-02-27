class LinkedNode:
    def __init__(self, x) -> None:
        self.val = x
        self.next = None

def findMid(head: LinkedNode) -> LinkedNode:
    if not head:
        return head
    slow, fast = head, head.next
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    return slow

def merge(head1: LinkedNode, head2: LinkedNode) -> LinkedNode:
    dummy = LinkedNode(0)
    tail = dummy
    while head1 and head2:
        if head1.val > head2.val:
            tail.next = head1
            head1 = head1.next
        else:
            tail.next = head2
            head2 = head2.next
        tail = tail.next
    tail.next = head1 or head2
    return dummy.next

def sortingLL(head: LinkedNode) -> LinkedNode:
    if not head or not head.next:
        return head

    mid = findMid(head)
    nextToMid = mid.next
    mid.next = None

    left = sortingLL(head)
    right = sortingLL(nextToMid)

    sortedList = merge(left, right)
    return sortedList


if __name__ == "__main__":

    N1 = LinkedNode(3)
    N2 = LinkedNode(1)
    N3 = LinkedNode(2)
    N4 = LinkedNode(7)
    N5 = LinkedNode(4)
    
    N1.next = N2
    N2.next = N3
    N3.next = N4
    N4.next = N5

    # print(findMid(N1).next.val) # Print : 7


    result = sortingLL(N1)

    while result:
        print(result.val)
        result = result.next



