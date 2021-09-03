# topological sort by bfs
from collections import deque

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    deg = [0] * N
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        # reverse graph
        G[b].append(a)
        deg[a] += 1

    todo = deque([])
    for i, e in enumerate(deg):
        if e == 0:
            todo.append(i)

    output = []
    while len(todo) > 0:
        node = todo.popleft()
        output.append(node)
        for i in G[node]:
            deg[i] -= 1
            if deg[i] == 0:
                todo.append(i)

    print(output[::-1])

if __name__=='__main__':
    main()        

    
