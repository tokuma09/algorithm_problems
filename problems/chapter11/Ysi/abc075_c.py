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
    
    def isSame(self, x, y):
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
    e = []
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        e.append([a, b])

    ans = 0
    for i in e:
        uf = UnionFind(N)
        for j in e:
            if i == j:
                continue
            uf.unite(j[0], j[1])
        
        res = 0
        for k in range(N):
            if uf.root(k) == k:
                res += 1
        
        if res > 1:
            ans += 1
     
    print(ans)
if __name__=='__main__':
    main()
