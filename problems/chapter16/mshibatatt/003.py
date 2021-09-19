# https://atcoder.jp/contests/jag2014autumn/tasks/icpc2014autumn_f

import sys
import copy
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

def dfs(G, s, seen, output, rev = False):
    # return set of reachable node from s    
    for nxt in G[s]:
        v, cap, _ = nxt
        if rev:
            # reverse path is alive is cap == 0
            cap = 1-cap
        if seen[v] or cap == 0:
            continue
        output.add(v)
        seen[v] = True
        output = dfs(G, v, seen, output, rev=rev)
    return output

def main():
    N, M, s, t = map(int, input().split())
    if N == M == s == t == 0:
        return 'end'
    s -= 1
    t -= 1
    ff = FordFulkerson(N)
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        ff.add_edge(a, b, 1)

    original_G = copy.deepcopy(ff.G)
    # make residual path
    current_flow = ff.flow(s, t)
    output = [current_flow, 0]
    
    # make a set S: reachable from s
    seen = [False] * N
    seen[s] = True
    S_reachable = dfs(ff.G, s, seen, set([s]))
    # make a set T: reachable to t
    seen = [False] * N
    seen[t] = True
    T_reachable = dfs(ff.G, t, seen, set([t]), True) 

    # check if there is u->v path where u in T and v in S
    for u, fr in enumerate(ff.G):
        for i, e  in enumerate(fr):
            v, cap, _ = e
            # skip if used in residual path
            if original_G[u][i][1] == 0 and cap == 1: 
                continue
            if v in S_reachable and u in T_reachable and cap == 1:
                output[0] = current_flow + 1
                output[1] += 1
  
    print(*output)
    return 'continue'

if __name__=='__main__':
    end_flag = 'continue'
    while end_flag == 'continue':
        end_flag = main()