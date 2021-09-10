class UnionFind():
    def __init__(self, n) -> None:
        self.par = [-1] * n
        self.siz = [1] * n

    def root(self, x):
        if self.par[x] == -1:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def issame(self, x, y):
        return self.root(x) == self.root(y)

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)

        if x == y:
            return False

        if self.siz[x] < self.siz[y]:
            x, y = y, x

        self.par[y] = x
        self.siz[x] += self.siz[y]
        return True

    def size(self, x):
        return self.siz[self.root(x)]
def main():
    N, M = map(int, input().split())
    if N == 0 and M == 0:
        return

    edge = []
    for i in range(M):
        a, b, c = map(int, input().split())
        edge.append([a-1, b-1, c])
    
    sort_edge = sorted(edge, key=lambda x:x[2])
    
    uf = UnionFind(N)
    res = []
    cost = 0
    for i, e in enumerate(sort_edge):
        a, b, c = e
        if uf.issame(a, b):
            continue
        else:
            uf.unite(a, b)
            res.append(i)
            cost += c
            if uf.size(a) == N:
                    break
    
    n=w=0
    for i in res:
        cost_i = 0
        uf2 = UnionFind(N)
        for j in range(M):
            if i == j:
                continue
            a, b, c = sort_edge[j]
            if uf2.issame(a, b):
                continue
            else:
                uf2.unite(a, b)
                cost_i += c
                if uf2.size(a) == N:
                    break
        if cost < cost_i or uf2.size(0) < N:
            n += 1
            w += sort_edge[i][2]
    print(n, w)
if __name__=='__main__':
    main()