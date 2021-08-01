import heapq
q2 = [] 
for i, e in enumerate([5,6,1]):
  heapq.heappush(q2, e)
  print('q2:', i, q2)

q3 = [5,6,1,2,7,3,4]
heapq.heapify(q3)
print('q3:', q3)
