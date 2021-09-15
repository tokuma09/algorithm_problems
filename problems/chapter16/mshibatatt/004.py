# https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163&lang=jp
from math import gcd
import sys
sys.setrecursionlimit(10000)

def floyd_warshall(G):
    N = len(G)
    dp = [[float('Inf')] * N for _ in range(N)]
    # init condition
    for i in range(N):
        dp[i][i] = 0
    for i, e in enumerate(G):
        for nxt in e:
            dp[i][nxt[0]] = nxt[1]
    
    for k in range(N):
        for i in range(N):
            for j in range(N):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
    
    return dp

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
    m, n = map(int, input().split())
    if m == n == 0:
        return True
    blue = list(map(int, input().split()))
    red = list(map(int, input().split()))
    
    s = 0
    t = m + n + 1
    ff = FordFulkerson(t+1)
    
    # index of blue cards are i
    for i in range(1, m+1):
        ff.add_edge(0, i, 1)
    # index of red cards are j
    for j in range(m+1, t):
        ff.add_edge(j, t, 1)
            
    for i in range(1, m+1):
        for j in range(m+1, t):
            b = blue[i-1]
            r = red[j-m-1]
            if gcd(b, r) > 1:
                ff.add_edge(i, j, 1)

    output = ff.flow(s, t)

    print(output)
    return False

if __name__ == '__main__':
    while True:
        if main():
            break