from collections import deque

class graph:
    def __init__(self, N, M, G) -> None:
        self.N = N
        self.M = M
        self.G = G
        self.todo_set = set(range(N))
        self.todo_que = deque([])

    def dfs(self, v):
        self.todo_set.remove(v)
        for i in self.G[v]:
            if i in self.todo_set:
                self.dfs(i)
            else:
                continue

    def bfs(self, v):
        self.todo_set.remove(v)
        self.todo_que.append(v)
        while len(self.todo_que) > 0:
            now = self.todo_que.popleft()
            for nxt in self.G[now]:
                if nxt in self.todo_set:
                    self.todo_set.remove(nxt)
                    self.todo_que.append(nxt)
                else:
                    continue

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        G[a-1].append(b-1)
        G[b-1].append(a-1)

    # DFS
    problem = graph(N, M, G)
    counter = 0
    while len(problem.todo_set) > 0:
        counter += 1
        v = problem.todo_set.pop()
        problem.todo_set.add(v)
        problem.dfs(v)
    print('DFS:', counter)

    # BFS
    problem = graph(N, M, G)
    counter = 0
    while len(problem.todo_set) > 0:
        counter += 1
        v = problem.todo_set.pop()
        problem.todo_set.add(v)
        problem.bfs(v)
    print('BFS:', counter)

if __name__=='__main__':
    main()


                


