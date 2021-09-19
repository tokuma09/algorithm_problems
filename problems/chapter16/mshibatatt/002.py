# https://onlinejudge.u-aizu.ac.jp/beta/room.html#RitsCamp18Day3/problems/F
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
    N, M, s, t = map(int, input().split())
    s -= 1
    t -= 1
    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v, d, c = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append([v, d, c])

    # find DAG including paths that are necessary for shortest path
    dist = floyd_warshall(G)
    shortest_path_length = dist[s][t]
    DAG = FordFulkerson(N)
    for i, e in enumerate(G):
        for v, d, c in e:
            if dist[s][i] + d + dist[v][t] == shortest_path_length:
                DAG.add_edge(i, v, c)

    # find minimum cut
    output = DAG.flow(s, t)
    print(output)

    
if __name__=='__main__':
    main()
