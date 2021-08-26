# https://atcoder.jp/contests/arc090/tasks/arc090_b

class WeightedUnionFind:
    def __init__(self, n) -> None:
        self.par = [-1]*n
        self.siz = [1]*n
        self.dist = [0]*n

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
        # merge x and y as
        #  weight(y) = weight(x) + w 

        w += self.dist[x]
        w -= self.dist[y]

        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False

        if self.size(x) < self.size(y):
            x, y ,w = y, x, -w

        self.par[y] = x
        self.siz[x] += self.siz[y]
        self.dist[y] = w
        return True
    
    def size(self, x):
        return self.siz[self.root(x)]

def main():
    N, M = map(int, input().split())
    lrd = []
    for _ in range(M):
        l, r, d = map(int, input().split())
        lrd.append([l-1, r-1, d])

    uf = WeightedUnionFind(N)
    output = 'Yes'
    for i in lrd:
        diff = uf.diff(i[0], i[1])
        if diff == None:
            uf.unite(i[0], i[1], i[2])
        elif diff != i[2]:
            output = 'No'
            break

    print(output)

if __name__=='__main__':
    main()