# Single Linked List Implementation

class Node:
    """ This class create a node"""
    def __init__(self, data='Head', next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = Node()

    def insert_at_beginning(self, data):
        # node = Node(2, 0xH40)
        node = Node(data, self.head.next)
        self.head.next = node

    def print_linked_list(self):
        if self.head.next is None:
            print('Linked list is Empty.')
            return
        
        current_node = self.head
        # Until current_node != None
        res_str = ''
        while current_node != None:
            res_str = res_str + str(current_node.data) + ' --> '
            current_node = current_node.next

        print(res_str)

if __name__ == '__main__':
    # ll --> linked list
    # node = head|None
    ll = LinkedList()
    ll.insert_at_beginning(15)
    ll.insert_at_beginning(10)
    ll.insert_at_beginning(5)
    ll.print_linked_list()
   