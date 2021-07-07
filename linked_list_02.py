# Single linked list implementation
"""
Function:
    1. search()
    2. insert_at()
    3. remove()
"""

class Node:
    def __init__(self, data='Head', next=None):
        self.data = data
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = Node()

    def get_length(self):
        cnt = 0
        current_node = self.head
        while current_node != None:
            cnt = cnt + 1
            current_node = current_node.next
        return cnt

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

    def search(self, search_item):
        current_node = self.head.next

        while current_node != None:
            if current_node.data == search_item:
                print('Data found in linked list')
                return
            current_node = current_node.next
        
        print('OOPS! Data not found.')
        
    def insert_at(self, location, data):
        if location<0 or location>self.get_length():
            print('Invalid location')
            return
        
        if self.head.next == None:
            #self.insert_at_beginning(data)
            node = Node(data, self.head.next)
            self.head.next = node
            return

        cnt = 0
        current_node = self.head
        while current_node != None:
            if cnt == location - 1:
                node = Node(data, current_node.next)
                current_node.next = node
                break
            current_node = current_node.next
            cnt += 1            

    def remove(self, remove_item):
        pass


if __name__ == '__main__':
    ll = LinkedList()
    # Insert values at specific location
    ll.insert_at(1, 10)
    ll.insert_at(2, 20)
    ll.insert_at(3, 30)
    ll.print_linked_list()
    ll.insert_at(2, 15)
    ll.print_linked_list()

    # Search
    ll.search(10)
    ll.search(50)

