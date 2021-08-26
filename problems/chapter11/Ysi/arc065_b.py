class UnionFind():
    def __init__(self, n) -> None:
        self.n = n
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
    
    def members(self, x):
        return [i for i in range(self.n) if self.issame(x, i)]

def main():
    N, K, L = map(int, input().split())
    load = []
    for _ in range(K):
        p, q = map(int, input().split())
        load.append([p-1, q-1])
    railway = []
    for _ in range(L):
        r, s = map(int, input().split())
        railway.append([r-1, s-1])
    
    ufL = UnionFind(N)
    ufR = UnionFind(N)

    for e in load:
        a, b = e
        ufL.unite(a, b)
    for e in railway:
        a, b = e
        ufR.unite(a, b)

    
    res = dict()
    roots = []
    for i in range(N):
        root = (ufL.root(i), ufR.root(i))
        roots.append(root)
        if root in res:
            res[root] += 1
        else:
            res[root] = 1
    
    ans = []
    for i in range(N):
        root = roots[i]
        ans.append(res[root])

    print(*ans)
if __name__=='__main__':
    main()