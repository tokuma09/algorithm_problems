# https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1350
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

def main():
    N, M = map(int, input().split())
    edge = []
    for _ in range(M):
        s, d, c = map(int, input().split())
        edge.append([s-1, d-1, c])
    
    edge.sort(key=lambda x: x[2])
    sst = []
    min_cost = 0
    uf = UnionFind(N)
    # make smallest spanning tree
    for i, e in enumerate(edge): 
        s, d, c = e
        if uf.issame(s, d):
            continue
        uf.unite(s, d)
        min_cost += c
        sst.append(i)
    
    output = [0, 0]
    # make smallest spanning tree from G excluding one edge
    for id in sst:
        uf = UnionFind(N)
        counter = 1
        cost = 0
        for i, e in enumerate(edge):
            s, d, c = e
            if id == i:
                continue
            if uf.issame(s, d):
                continue
            uf.unite(s, d)
            cost += c
            counter += 1
        if counter < N or cost > min_cost:
            output[0] += 1
            output[1] += edge[id][2]

    print(*output)
          
if __name__=='__main__':
    main()
