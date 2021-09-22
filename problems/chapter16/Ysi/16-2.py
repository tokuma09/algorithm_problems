def floyd_warshall(G):
    N = len(G)
    dp = [[float('Inf')] * N for _ in range(N)]

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
    N, M, s, t = map(int, input().split())
    s -= 1
    t -= 1
    
    ff = FordFulkerson(N)
    G = [[] for _ in range(N)]
    for i in range(M):
        u, v, d, c = map(int, input().split())
        G[u-1].append([v-1, d, c])   

    dist = floyd_warshall(G)
    shortest_path_length = dist[s][t]

    for i, e in enumerate(G):
        for v, d, c in e:
            if dist[s][i] + d + dist[v][t] == shortest_path_length:
                ff.add_edge(i, v, c)

    # find minimum cut
    output = ff.flow(s, t)
    print(output)
        
if __name__=='__main__':
    main()