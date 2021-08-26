# topological sort by bfs
from collections import deque

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)

    seen = [False]*N
    todo = deque([])

    output = []
    while len(output) < N:
        for i, e in enumerate(seen):
            if not e:
                seen[i] = True
                todo.append(i)
                break
        sub_output = []
        while len(todo) > 0:
            node = todo.popleft()
            sub_output.append(node)
            for i in G[node]:
                if seen[i]:
                    continue
                seen[i] = True
                todo.append(i)
        output = sub_output + output

    print(output)

if __name__=='__main__':
    main()        

    
