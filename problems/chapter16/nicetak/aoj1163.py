# Ford-Fulkerson algorithm
class FordFulkerson:
    def __init__(self, N):
        self.N = N
        self.G = [[] for i in range(N)]

    def add_edge(self, fr, to, cap):
        forward = [to, cap, None]
        forward[2] = backward = [fr, 0, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def add_multi_edge(self, v1, v2, cap1, cap2):
        edge1 = [v2, cap1, None]
        edge1[2] = edge2 = [v1, cap2, edge1]
        self.G[v1].append(edge1)
        self.G[v2].append(edge2)

    def dfs(self, v, t, f):
        if v == t:
            return f
        used = self.used
        used[v] = 1
        for e in self.G[v]:
            w, cap, rev = e
            if cap and not used[w]:
                d = self.dfs(w, t, min(f, cap))
                if d:
                    e[1] -= d
                    rev[1] += d
                    return d
        return 0

    def flow(self, s, t):
        flow = 0
        f = INF = 10**9 + 7
        N = self.N
        while f:
            self.used = [0]*N
            f = self.dfs(s, t, INF)
            flow += f
        return flow

import math

def solve(M, N):
    bs = []
    while len(bs) < M:
        bs += list(map(int, input().split()))
    cs = []
    while len(cs) < N:
        cs += list(map(int, input().split()))
    ff = FordFulkerson(N + M + 2)
    s, t = N + M, N + M + 1
    for i in range(M):
        ff.add_edge(s, i, 1)
    
    for j in range(N):
        ff.add_edge(j + M, t, 1)

    for i in range(M):
        for j in range(N):
            if math.gcd(bs[i], cs[j]) > 1:
                ff.add_edge(i, j + M, 1)

    return ff.flow(s, t)

def main():
    while True:
        M, N = map(int, input().split())
        if M == 0 and N == 0:
            break
        else:
            print(solve(M, N))

if __name__=='__main__':
    main()
