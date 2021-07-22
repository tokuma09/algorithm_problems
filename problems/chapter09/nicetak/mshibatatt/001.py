from collections import deque

s = deque([])
s.append(1)  # [1]
s.append(2)  # [1, 2]
s.append(3)  # [1, 2, 3]
s.pop()      # 一番上から取り除く [1, 2, 3] -> [1, 2]
s.pop()      # [1, 2] -> [1]
s.pop()      # [1] -> []

q = deque([])
q.append(1)  # [1]
q.append(2)  # [1, 2]
q.append(3)  # [1, 2, 3]
q.popleft()  # 一番下から取り除く [1, 2, 3] -> [2, 3]
q.popleft()  # [2, 3] -> [3]
q.popleft()  # [3] -> []


from problems.chapter08.mshibatatt.linked_list import Node, DoubleLinkedList 

s = DoubleLinkedList()
s.insert(Node(3))  # [3]
s.insert(Node(2))  # [2, 3]
s.insert(Node(1))  # [1, 2, 3]
s.pop_left() # 一番上から取り除く [1, 2, 3] -> [1, 2]
s.pop_left() # [1, 2] -> [1]
s.pop_left() # [1] -> []

q = DoubleLinkedList()
q.insert(Node(3))  # [3]
q.insert(Node(2))  # [2, 3]
q.insert(Node(1))  # [1, 2, 3]
q.pop()      # 一番下から取り除く [1, 2, 3] -> [2, 3]
q.pop()      # [2, 3] -> [3]
q.pop()      # [3] -> []