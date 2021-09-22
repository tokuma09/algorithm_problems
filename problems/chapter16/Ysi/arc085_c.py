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
    N = int(input())
    A = list(map(int, input().split()))

    ff = FordFulkerson(N+2)

    I = 0
    O = 0
    for i in range(1, N+1):
        if A[i-1] < 0:
            ff.add_edge(0, i, -A[i-1])
            I += -A[i-1]
        else:
            ff.add_edge(i, N+1, A[i-1])
            O += A[i-1]
    INF = float("inf")
    for i in range(1, N):
        for j in range(i, N+1):
            if j%i == 0:
                ff.add_edge(i, j, INF)
    
    ans = O - ff.flow(0, N+1)
    print(ans)
if __name__=='__main__':
    main()