class WeightedUnionFind():
    def __init__(self, n) -> None:
        self.par = [-1] * n
        self.siz = [1] * n
        self.dist = [0] * n

    def root(self, x):
        if self.par[x] == -1:
            return x
        else:
            rootx = self.root(self.par[x])
            self.dist[x] += self.dist[self.par[x]]
            self.par[x] = rootx
            return self.par[x]

    def issame(self, x, y):
        return self.root(x) == self.root(y)

    def diff(self, x, y):
        if self.issame(x, y):
            return self.dist[y] - self.dist[x]
        else:
            return None

    def unite(self, x, y, w):
        w += self.dist[x] - self.dist[y]
        x = self.root(x)
        y = self.root(y)

        if x == y:
            return False

        if self.siz[x] < self.siz[y]:
            x, y, w = y, x, -w

        self.par[y] = x
        self.siz[x] += self.siz[y]
        self.dist[y] = w
        return True

    def size(self, x):
        return self.siz[self.root(x)]
def main():
    N, M = map(int, input().split())
    info = []
    for _ in range(M):
        L, R, D = map(int, input().split())
        info.append([L-1, R-1, D])

    wuf = WeightedUnionFind(N)
    ans = "Yes"
    for i in range(M):
        L, R, D = info[i]
        if wuf.diff(L, R) == None:
            wuf.unite(L, R, D)
        elif wuf.diff(L, R) != D:
            ans = "No"
            break
    
    print(ans)
if __name__=='__main__':
    main()