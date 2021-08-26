class Node:
    def __init__(self, name):
        self.name = name
        self.prev = None
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while (temp):
            print (temp.name)
            temp = temp.next

    # pの直後にvを挿入する
    def insert(self, v, p = None):
        v.next = p.next
        p.next.prev = v
        p.next = v
        v.prev = p

    def erase(v):
        if v == None:
            return
        v.prev.next = v.next
        v.next.prev = v.prev