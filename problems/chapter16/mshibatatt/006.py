# https://atcoder.jp/contests/arc085/tasks/arc085_c

import sys
sys.setrecursionlimit(10000)

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
        seen = self.seen
        seen[v] = True
        for e in self.G[v]:
            w, cap, rev = e
            if cap and not seen[w]:
                d = self.dfs(w, t, min(f, cap))
                if d:
                    e[1] -= d
                    rev[1] += d
                    return d
        return 0
 
    def flow(self, s, t):
        flow = 0
        f = INF = float('inf')
        N = self.N
        while f:
            self.seen = [False]*N
            f = self.dfs(s, t, INF)
            flow += f
        return flow

def main():
    N = int(input())
    a = list(map(int, input().split()))
    ff = FordFulkerson(N+2)
    
    sum_a = 0
    for i, x in enumerate(a):
        if x < 0:
            ff.add_edge(N, i, abs(x))
            ff.add_edge(i, N+1, 0)
        else:
            ff.add_edge(N, i, 0)
            ff.add_edge(i, N+1, abs(x))
            sum_a += x
   
    for i in range(N):
        for j in range(i+1, N):
            if (j+1) % (i+1) == 0:
                ff.add_edge(i, j, float('inf'))
    
    output = sum_a - ff.flow(N, N+1)
    print(output)

if __name__=='__main__':
    main()