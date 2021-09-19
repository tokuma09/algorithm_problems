class Edge:
    def __init__(self, rev, fr, to, cap):
        self.rev = rev
        self.fr = fr
        self.to = to
        self.cap = cap
        self.icap = cap

class Graph:
    def __init__(self, N):
        self.N = N
        self.G = [[] for _ in range(N)]

    def get_redge(self, e):
        return self.G[e.to][e.rev]

    def run_flow(self, e, f):
        e.cap -= f
        self.get_redge(e).cap += f

    def add_edge(self, fr, to, cap):
        fromrev = len(self.G[fr])
        torev = len(self.G[to])
        self.G[fr].append(Edge(torev, fr, to, cap))
        self.G[to].append(Edge(fromrev, to, fr, 0))

class FordFulkerson:
    def __init__(self):
        self.used = []

    def dfs(self, graph, v, t, f):
        if v == t:
            return f
        
        self.used[v] = True
        for e in graph.G[v]:
            if e.cap != 0 and not self.used[e.to]:
                flow = self.dfs(graph, e.to, t, min(f, e.cap))
                if flow != 0:
                    graph.run_flow(e, flow)
                    return flow
        return 0

    def solve(self, graph, s, t):
        res = 0
        INF = 10**9 + 7
        while True:
            self.used = [0] * graph.N
            flow = self.dfs(graph, s, t, INF)
            if flow == 0:
                return res

            res += flow
        
        return 0

from queue import Queue

def solve(graph, N, s, t):
    ff = FordFulkerson()
    B = ff.solve(graph, s, t)

    S = [False] * N
    T = [False] * N

    que = Queue()
    que.put(s)
    S[s] = True
    while (not que.empty()):
        v = que.get()
        for e in graph.G[v]:
            if (e.cap > 0) & (not S[e.to]):
                S[e.to] = True
                que.put(e.to)

    que.put(t)
    T[t] = True
    while (not que.empty()):
        v = que.get()
        for e in graph.G[v]:
            if (graph.get_redge(e).cap > 0) & (not T[e.to]):
                T[e.to] = True
                que.put(e.to)

    res = 0
    for v in range(N):
        if T[v]:
            for e in graph.G[v]:
                if (e.cap > 0) & (e.cap == e.icap) & (S[e.to]):
                    res += 1

    ma = B + 1 if res else B

    print(str(ma) + " " + str(res))

def main():
    while True:
        N, M, s, t = map(int, input().split())
        if N == 0:
            break
        else:
            s -= 1
            t -= 1
            G = Graph(N)
            for _ in range(M):
                a, b = map(int, input().split())
                a -= 1
                b -= 1
                G.add_edge(a, b, 1)

            solve(G, N, s, t)

if __name__=='__main__':
    main()



    
