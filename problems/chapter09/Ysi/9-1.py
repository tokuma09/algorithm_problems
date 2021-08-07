from LinkedList import LinkedList, Node

class stack:
    def __init__(self):
        self.li = LinkedList()
    
    def append(self, v):
        v = Node(v)
        self.li.insert(v)
    
    def pop(self):
        v = self.li.head.prev
        self.li.erase(v)
        return v.name

class que:
    def __init__(self):
        self.li = LinkedList()

    def enque(self, v):
        v = Node(v)
        self.li.insert(v)
    
    def deque(self):
        v = self.li.head.next
        self.li.erase(v)
        return v.name

def main():
    l = [0, 2, 3, 4, 5]

    # stack
    s = stack()
    for i in range(len(l)):
        s.append(l[i])

    for i in range(len(l)):
        print(s.pop())

    # que
    q = que()
    for i in range(len(l)):
        q.enque(l[i])
    
    for i in range(len(l)):
        print(q.deque())
if __name__=='__main__':
    main()