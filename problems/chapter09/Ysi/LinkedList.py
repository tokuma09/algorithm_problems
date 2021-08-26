class Node:
    def __init__(self, name):
        self.name = name
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = Node(None)
        self.head.prev = self.head
        self.head.next = self.head

    def printList(self):
        temp = self.head
        while (temp):
            print (temp.name)
            temp = temp.next

    # pの直後にvを挿入する
    def insert(self, v, p = None):
        if p == None:
            pos = self.head
        else:
            pos = p
        v.next = pos.next
        pos.next.prev = v
        pos.next = v
        v.prev = pos

    def erase(self, v):
        if v == None:
            return
        v.prev.next = v.next
        v.next.prev = v.prev
        del v

