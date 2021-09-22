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
    while True:
        N, M, S, T = map(int, input().split())
        if N == M == S == T == 0:
            break
        ff = FordFulkerson(N+1)
        edge = set()
        for _ in range(M):
            a, b = map(int, input().split())
            edge.add((a, b))
            ff.add_edge(a, b, 1)
        import copy
        original = copy.deepcopy(ff.G)
        ans1 = ff.flow(S, T)
        
        def dfs(G, v, visited, reverse = False):
            if visited[v] == True:
                return
            
            visited[v] = True
            for e in G[v]:
                u, cap, rev = e
                if reverse:
                    cap = 1 - cap
                if cap > 0:
                    dfs(G, u, visited, reverse)

        visitedS = [False]*(N+1)
        visitedT = [False]*(N+1)
        dfs(ff.G, S, visitedS)
        dfs(ff.G, T, visitedT, True)
        
        ans2 = 0
        for u, fr in enumerate(ff.G):
            for i, e  in enumerate(fr):
                v, cap, _ = e
                # skip if used in residual path
                if original[u][i][1] == 0 and cap == 1: 
                    continue
                if visitedS[v] and visitedT[u]:
                    ans2 += 1
        if ans2 > 0:
            ans1 += 1
        print(ans1, ans2)
if __name__=='__main__':
    main()