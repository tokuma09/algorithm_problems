# https://atcoder.jp/contests/abc120/tasks/abc120_d

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
        
        # make the number of child of y is smaller than that of x 
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
    edges = []
    for _ in range(M):
        a, b = map(int, input().split())
        edges.append([a-1, b-1])

    uf = UnionFind(N)
    # inconv after all bridge has broken
    output = [int(N*(N-1)/2)]

    # after 0~i bridges have broken
    #   <=> after constructing i+1~M bridges from no bridge 
    for _ in range(M-1):
        bridge = edges.pop()
        # count inconv island by substructing the number of connected islands
        if uf.issame(bridge[0], bridge[1]):
            output.append(output[-1])
        else:
            output.append(output[-1] - uf.size(bridge[0])*uf.size(bridge[1]))
        uf.unite(bridge[0], bridge[1])

    # print answer
    for i in output[::-1]:
        print(i)

if __name__=='__main__':
    main()
