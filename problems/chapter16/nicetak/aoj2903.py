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
    INF = 10**9
    R, C = map(int, input().split())
    ss = [input() for _ in range(R)]
    s = R * C * 3
    t = R * C * 3 + 1
    num_black = 0
    num_adj = 0
    ff = FordFulkerson(R * C * 3 + 2)
    for i in range(R):
        for j in range(C):
            if ss[i][j] == "#":
                num_black += 1
                if (i + 1 < R) and (ss[i+1][j] == "#"):
                    num_adj += 1
                    v_new = i * C + j + R * C
                    ff.add_edge(v_new, t, 1)
                    ff.add_edge(i * C + j, v_new, INF)
                    ff.add_edge((i + 1) * C + j, v_new, INF)

                if (j + 1 < C) and (ss[i][j + 1] == "#"):
                    num_adj += 1
                    v_new = i * C + j + R * C * 2
                    ff.add_edge(s, v_new, 1)
                    ff.add_edge(v_new, i * C + j, INF)
                    ff.add_edge(v_new, i * C + j + 1, INF)

    flow = ff.flow(s, t)

    print(num_black - (num_adj - flow))




if __name__=='__main__':
    main()
