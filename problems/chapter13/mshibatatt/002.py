# code to determine if there is s-t path
from collections import deque

class graph:
    def __init__(self, N, M, G) -> None:
        self.N = N
        self.M = M
        self.G = G
        self.seen = [False]*N
        self.todo = deque([])

    def bfs(self, s, t):
        self.seen[s] = True
        self.todo.append(s)
        while len(self.todo) > 0:
            now = self.todo.popleft()
            for nxt in self.G[now]:
                if self.seen[nxt]:
                    continue
                else:
                    self.seen[nxt] = True
                    self.todo.append(nxt)
            if self.seen[t]:
                return

def main():
    N, M, s, t = map(int, input().split())
    s -= 1
    t -= 1
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)
        G[b].append(a)
    
    problem = graph(N, M, G)
    problem.bfs(s, t)

    if problem.seen[t]:
        output = 'Yes'
    else:
        output = 'No'

    print(output)

if __name__=='__main__':
    main()

 