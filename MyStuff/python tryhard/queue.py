
queue = []

def enqueue(item):
    global queue
    queue.append(item)

def dequeue():
    global queue
    if len(queue) != 0:
        return queue.pop(0)

def peekqueue():
    global queue
    if len(queue) != 0:
        return queue[0]
    