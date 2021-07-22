# code 8.6 in p.132
# c.f. https://github.com/TheAlgorithms/Python/blob/master/data_structures/linked_list/doubly_linked_list_two.py
class Node:
    def __init__(self, data, prev = None, next = None):
        self.data = data
        self.prev = None
        self.next = None

    def __str__(self):
        return f"{self.data}"
    
class DoubleLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.prev = self.nil
        self.nil.next = self.nil

    def __iter__(self):
        node = self.nil.next
        while node.data:
            yield node
            node = node.next
    
    # printList()
    def __str__(self):
        return "->".join([str(item.data) for item in self])

    # insert v after p
    def insert(self, v, p=None):
        if p == None:
            pos = self.nil
        else: pos = p 
        v.next = pos.next
        pos.next.prev = v
        pos.next = v
        v.prev = p
    
    # insert v after p
    def erase(self, v):
        if v == None: return 
        v.prev.next = v.next
        v.next.prev = v.prev
        del v
    
    # get i-th data 
    def get(self, i):
        output = self.nil
        for j in range(i):
            output = output.next
        return output.data

class SingleLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.next = self.nil

    def __iter__(self):
        node = self.nil.next
        while node.data:
            yield node
            node = node.next
    
    # printList()
    def __str__(self):
        return "->".join([str(item.data) for item in self])

    # insert v after p
    def insert(self, v, p=None):
        if p == None:
            pos = self.nil
        else: pos = p 
        v.next = pos.next
        pos.next = v
    
    # insert v after p
    def erase(self, v):
        if v == None: return
        for i in self:
            if i.next.data == v.data:
                i.next = v.next
                break
        del v
    
    # get i-th data 
    def get(self, i):
        output = self.nil
        for j in range(i):
            output = output.next
        return output.data

def main():
    # yamamoto watanabe ito takahashi suzuki sato
    names = list(input().split())
    # watanabe
    deleted = input()
    
    linked_list = DoubleLinkedList()
    for i in names:
        node = Node(i)
        linked_list.insert(node)
        if i == deleted:
            deleted = node
    
    print('double')
    print(linked_list)
    linked_list.erase(deleted)
    print(linked_list)
    print(linked_list.get(3))


    linked_list = SingleLinkedList()
    for i in names:
        node = Node(i)
        linked_list.insert(node)
        if i == deleted:
            deleted = node

    print('single')
    print(linked_list)
    linked_list.erase(deleted)
    print(linked_list)
    print(linked_list.get(3))

if __name__=='__main__':
    main() 