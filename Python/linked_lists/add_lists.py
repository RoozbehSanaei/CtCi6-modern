class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insert(head, data):
    new_node = Node(data)
    new_node.next = head
    head = new_node
    return head

def printList(head):
    """
    Prints the contents of a linked list, starting at the given head node.

    Args:
        head: The head node of the linked list.
    """
    node = head
    while node:
        print(str(node.data) + "-->", end="")
        node = node.next
    print("NULL")


def add_iterative(list1, list2):
    list3 = list3Tail = Node(0)
    carry = 0
    
    while list1 or list2 or carry:
        value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)
        carry, value = divmod(value, 10)
        list3Tail.next = list3Tail = Node(value)
        list1 = list1.next if list1 else None
        list2 = list2.next if list2 else None

    return list3.next


def add_recursive(list1, list2, carry=0):
    if not list1 and not list2 and carry == 0:
        return None

    value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)
    result_node = Node(value % 10)
    result_node.next = add_recursive(list1.next if list1 else None, list2.next if list2 else None, 1 if value > 9 else 0)
    return result_node

def length(head):
    len = 0
    while head:
        len += 1
        head = head.next
    return len


def pad_list(list_head, padding):
    for i in range(padding):
        list_head = Node(0)
    return list_head


def add_followup_helper(list1, list2, carry):
    if not list1 and not list2 and carry == 0:
        return None
    
    next_list1 = list1.next if list1 else None
    next_list2 = list2.next if list2 else None
    
    result = add_followup_helper(next_list1, next_list2, carry)
    
    value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)
    
    return insert(result, value % 10) if (result := insert(result, value % 10)) else result
    
    carry = 1 if value > 9 else 0


def add_followup(list1, list2):
    len1, len2 = length(list1), length(list2)

    if len1 > len2:
        list2 = pad_list(list2, len1 - len2)
    else:
        list1 = pad_list(list1, len2 - len1)

    carry = 0
    list3 = add_followup_helper(list1, list2, carry)

    if carry:
        list3 = insert(list3, carry)

    return list3

if __name__ == '__main__':
    list1 = None
    list1 = insert(list1, 6)
    list1 = insert(list1, 1)
    list1 = insert(list1, 7)
    print("List1:  ", end="")
    printList(list1)

    list2 = None
    list2 = insert(list2, 2)
    list2 = insert(list2, 9)
    list2 = insert(list2, 5)
    print("List2:  ", end="")
    printList(list2)

    list3 = add_iterative(list1, list2)
    print("Iterative Solution: ")
    print("List3:  ", end="")
    printList(list3)

    list4 = add_recursive(list1, list2, 0)
    print("Recursive Solution: ")
    print("List4:  ", end="")
    printList(list4)

    list1 = None
    list1 = insert(list1, 4)
    list1 = insert(list1, 3)
    list1 = insert(list1, 2)
    list1 = insert(list1, 9)
    print("\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list")
    print("List1:  ", end="")
    printList(list1)

    list2 = None
    list2 = insert(list2, 9)
    list2 = insert(list2, 9)
    list2 = insert(list2, 8)

    print("List2:  ", end="")
    printList(list2)

    list3 = add_followup(list1, list2)
    print("Adding two above lists")
    print("List3:  ", end="")
    printList(list3)
