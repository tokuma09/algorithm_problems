def main():
  N, M = map(int, input().split())
  G = []
  for _ in range(M):
    G.append(list(map(int, input().split())))
  
  seen = [1]*(N+1)
  todo = []
  pattern = [1]*(N+1)
  
  seen[1] = 0
  pattern[1] = 1
  todo.append(1)
  
  while len(todo) > 0:
    v = todo.pop()
    for i in range(M):
      if G[i][0] == v:
        if seen(G[i][1]) > 0:
          pass
        else:
          seen[G[i][1]] = seen[v] + 1
          pattern[G[i][1]] += pattern[v] 
          todo.append(G[i][1])
      
      if G[i][1] == v:
        if seen(G[i][0]) > 0:
          pass
        else:
          seen[G[i][0]] = seen[v] + 1
          pattern[G[i][0]] += pattern[v]
          todo.append(G[i][0])
  
  output = pattern[-1]%(10**9 + 7)
  print(output)

if __name__=='__main__':
  main()
