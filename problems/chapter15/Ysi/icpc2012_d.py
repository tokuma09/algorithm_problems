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
    while True:
        N, M = map(int, input().split())
        if N == 0 and M == 0:
            break
        edge = []
        for i in range(M):
            a, b, c = map(int, input().split())
            edge.append([a-1, b-1, c])
        
        sort_edge = sorted(edge, key=lambda x:x[2])
        
        uf = UnionFind(N)
        res = []
        for a, b, c in sort_edge:
            if uf.issame(a, b):
                continue
            else:
                uf.unite(a, b)
                res.append(c)
        ans = res[N//2 - 1]
        print(ans)
if __name__=='__main__':
    main()