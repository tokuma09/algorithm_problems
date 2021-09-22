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
    G = []
    for _ in range(r):
        G.append(input())

    # consider as minimun capacity cut
    ff = FordFulkerson(r*c*3 + 2)
    s, t = r*c*3, r*c*3 + 1 
    num_blank, num_adjacent = 0, 0
    INF = float("inf")
    for i in range(r):
        for j in range(c):
            if G[i][j] == '#':
                num_blank += 1
                v = i*c + j
                # if adjacent in row
                if i+1 < r and G[i+1][j] == '#':
                    num_adjacent += 1
                    newv = v + r*c
                    ff.add_edge(newv, t, 1)
                    ff.add_edge(v, newv, INF)
                    ff.add_edge(v+c, newv, INF)
                    
                # if adjacent in col
                if j+1 < c and G[i][j+1] == '#':
                    num_adjacent += 1
                    newv = v + r*c*2
                    ff.add_edge(s, newv, 1)
                    ff.add_edge(newv, v, INF)
                    ff.add_edge(newv, v+1, INF)
    
    ans = num_blank - num_adjacent + ff.flow(s, t)
    print(ans)
if __name__=='__main__':
    main()