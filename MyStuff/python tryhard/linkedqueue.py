class Node:
    def __init__(self, item, nice):
        self.item = item
        self.nice = nice
        self.next = None
        self.prev = None

class Queue:
    def __init__(self):
        self.head = None
        self.last = None

    def enqueue(self, item, nice):
        if self.last is None:   # same as pointer == NULL
            self.head = Node(item, nice)
            self.last = self.head
        else:
            target = self.head
            while target.next is not None:
                if target.next.nice >= nice:
                    target = target.next
                else:
                    break
            if target == self.head:
                if target.nice >= nice:
                    temp = self.head.next
                    self.head.next = Node(item, nice)
                    self.head.next.prev = self.head
                    self.head.next.next = temp
                else:
                    temp = self.head
                    self.head = Node(item, nice)
                    self.head.next = temp
                    self.head.prev = None
            elif target == self.last:
                if target.nice >= nice:
                    self.last = Node(item, nice)
                    self.last.prev = target
                    target.next = self.last
                else:
                    temp = target.prev
                    target.prev = Node(item, nice)
                    target.prev.prev = temp
                    target.prev.next = target
                    temp.next = target.prev
            else:
                temp = target.next
                target.next = Node(item, nice)
                target.next.prev = target
                target.next.next = temp
                temp.prev = target.next
            
        
    def dequeue(self):
        if self.head is None:
            return None
        else:
            #get data from head node
            temp = self.head.item
            #hide head node away
            self.head = self.head.next
            self.head.prev = None
            return temp

    def peek(self):
        return self.head.item

    def isEmpty(self):
        return self.head is None

    def getList(self):
        result = []
        temp = self.head
        while temp is not None:
            result += [temp.item]
            temp = temp.next
        return result

queue = Queue()

queue.enqueue(4, 1)
queue.enqueue(5, 1)
queue.enqueue(6, 1)
queue.enqueue(7, 1)
print(queue.getList())