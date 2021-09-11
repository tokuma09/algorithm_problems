# https://atcoder.jp/contests/jag2012autumn/tasks/icpc2012autumn_c?lang=ja
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
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        return 'end'
    edge = []
    for _ in range(m):
        s, t, c = map(int, input().split())
        edge.append([s-1, t-1, c])

    edge.sort(key=lambda x: x[2])
    uf = UnionFind(n)
    med = n // 2 
    counter = 0

    for s, t, c in edge:
        if uf.issame(s, t):
            continue
        uf.unite(s, t)
        counter += 1
        if counter == med:
            print(c)
            break
    return 'continue'
    
if __name__=='__main__':
    end_flag = 'continue'
    while end_flag == 'continue':
        end_flag = main()