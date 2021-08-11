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
    edge = []
    for i in range(M):
        a,b = map(int, input().split())
        a -= 1
        b -= 1
        edge.append([a, b])
    edge.reverse()
    res = N * (N-1) // 2
    ans = [res]
    uf = UnionFind(N)
    for e in edge:
        a, b = e

        if uf.issame(a, b):
            ans.append(res)
        else:
            res -= uf.size(a)*uf.size(b)
            uf.unite(a, b)
            ans.append(res)
    
    ans.reverse()
    for i in range(1,M+1):
        print(ans[i])

if __name__=='__main__':
    main()