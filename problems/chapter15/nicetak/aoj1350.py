class UnionFind():
    def __init__(self, n) -> None:
        self.par = [-1] * n
        self.siz = [1] * n
    
    # return root of x
    def root(self, x):
        if self.par[x] == -1:
            return x
        else: 
            self.par[x] = self.root(self.par[x])
            return self.par[x]
    
    # return if x and y are in the same group
    def issame(self, x, y):
        return self.root(x) == self.root(y)
    
    # combine group with x and one with y
    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)

        if x == y:
            return False
        if self.siz[x] < self.siz[y]:
            x, y = y, x
        
        # make y child of x
        self.par[y] = x
        self.siz[x] += self.siz[y]

        return True
        
    def size(self, x):
        return self.siz[self.root(x)]


def kruskal(edges, n, id_ommit = -1):
    uf = UnionFind(len(edges))
    edges_used = []
    cost = 0
    for i in range(len(edges)):
        s, t, w = edges[i][0], edges[i][1], edges[i][2]
        if (i != id_ommit) & (not uf.issame(s, t)):
            uf.unite(s, t)
            edges_used.append(i)
            cost += w

    if len(edges_used) < n - 1:
        cost = 10**13 # INF

    return edges_used, cost


def main():
    N, M = map(int, input().split())
    edges = []
    for _ in range(M):
        s, t, w = map(int, input().split())
        edges.append([s-1, t-1, w])

    edges = sorted(edges, key=lambda x: x[2])

    mst, cost_mst = kruskal(edges, N)

    cnt = 0
    cost = 0
    for id in mst:
        st, cost_st = kruskal(edges, N, id)
        if cost_st > cost_mst:
            cnt += 1
            cost += edges[id][2]

    print(str(cnt) + " " + str(cost))
    

if __name__=='__main__':
    main()
