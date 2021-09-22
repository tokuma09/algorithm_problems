import sys
sys.setrecursionlimit(10 ** 7)
 
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

def main():
    r, c = map(int, input().split())
    N = r*c
    ff = FordFulkerson(N+2)

    C = []
    for _ in range(r):
        row = list(input())
        C.append(row)
        
    size = 0
    for i in range(r):
        for j in range(c):
            if C[i][j] == '.':
                v = i*c + j
                size += 1
                if (i+j) % 2:
                    ff.add_edge(N, v, 1)
                    if i > 0 and C[i-1][j] == '.':
                        ff.add_edge(v, v-c, 1)
                    if j > 0 and C[i][j-1] == '.':
                        ff.add_edge(v, v-1, 1)
                else:
                    ff.add_edge(v, N+1, 1)              
                    if i > 0 and C[i-1][j] == '.':
                        ff.add_edge(v-c, v, 1)
                    if j > 0 and C[i][j-1] == '.':
                        ff.add_edge(v-1, v, 1)
    ans = size - ff.flow(N, N+1)
    print(ans)
if __name__=='__main__':
    main()