# https://atcoder.jp/contests/abc075/tasks/abc075_c

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
    edges = []
    for _ in range(M):
        a, b = map(int, input().split())
        edges.append([a-1, b-1])

    output = 0
    for i in edges:
        uf = UnionFind(N)
        for j in edges:
            if i == j:
                continue
            uf.unite(j[0], j[1])
        
        root_num = 0
        for k in range(N):
            if uf.root(k) == k:
                root_num += 1
        
        if root_num > 1:
            output += 1
    
    print(output)

if __name__=='__main__':
    main()
