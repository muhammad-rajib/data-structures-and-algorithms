# Queue Implementation
class Queue:
    # Initialized an empty queue
    def __init__(self):
        self.queue = []

    # Insert item to queue
    def enqueue(self, add_item):
        self.queue.append(add_item)

    def dequeue(self):
        if len(self.queue) < 1:
            return None
        return self.queue.pop(0)

    def show_queue(self):
        print(self.queue)

q = Queue()
q.enqueue(10)
q.enqueue(20)
q.enqueue(30)

q.show_queue()

q.dequeue()
q.dequeue()

q.show_queue()