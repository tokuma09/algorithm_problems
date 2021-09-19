# https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2018Day1/problems/H
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
    G = []
    for _ in range(r):
        G.append(input())

    # consider as minimun capacity cut
    ff = FordFulkerson(r*c*3 + 2)
    s, t = r*c*3, r*c*3 + 1 
    num_blank, num_adjacent = 0, 0
    for i in range(r):
        for j in range(c):
            if G[i][j] == '#':
                num_blank += 1
                v = i*c + j
                # if adjacent in row, cannot both 0
                if i > 0 and G[i-1][j] == '#':
                    num_adjacent += 1
                    newv = v + r*c
                    ff.add_edge(newv, t, 1)
                    ff.add_edge(v, newv, float('inf'))
                    ff.add_edge(v-c, newv, float('inf'))
                    
                # if adjacent in col, cannot both 1
                if j > 0 and G[i][j-1] == '#':
                    num_adjacent += 1
                    newv = v + r*c*2
                    ff.add_edge(s, newv, 1)
                    ff.add_edge(newv, v, float('inf'))
                    ff.add_edge(newv, v-1, float('inf'))
    
    output = num_blank - num_adjacent + ff.flow(s, t)
    print(output)

if __name__=='__main__':
    main()