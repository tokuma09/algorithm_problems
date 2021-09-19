# https://atcoder.jp/contests/soundhound2018/tasks/soundhound2018_c
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
    r, c = map(int, input().split())
    N = r * c
    G = []
    for _ in range(r):
        G.append(input())

    ff = FordFulkerson(N+2)
    size = 0
    # make two side graph
    # N: start, N+1: goal
    for i in range(r):
        for j in range(c):
            if G[i][j] == '.':
                color = (i + j) % 2
                v = i*c + j
                size += 1
                if color:
                    ff.add_edge(N, v, 1)
                    if i > 0 and G[i-1][j] == '.':
                        ff.add_edge(v, v-c, 1)
                    if j > 0 and G[i][j-1] == '.':
                        ff.add_edge(v, v-1, 1)
                else:
                    ff.add_edge(v, N+1, 1)              
                    if i > 0 and G[i-1][j] == '.':
                        ff.add_edge(v-c, v, 1)
                    if j > 0 and G[i][j-1] == '.':
                        ff.add_edge(v-1, v, 1)
                  

    output = size - ff.flow(N, N+1)
    print(output)

if __name__=='__main__':
    main()