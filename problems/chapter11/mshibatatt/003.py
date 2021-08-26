# https://atcoder.jp/contests/abc049/tasks/arc065_b

from typing import Counter


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
    N, K, L = map(int, input().split())
    roads = []
    rails = []
    for _ in range(K):
        a, b = map(int, input().split())
        roads.append([a-1, b-1])

    for _ in range(L):
        a, b = map(int, input().split())
        rails.append([a-1, b-1])

    output = []
    uf_road = UnionFind(N)
    uf_rail = UnionFind(N)

    for i in roads:
        uf_road.unite(i[0], i[1])
    for i in rails:
        uf_rail.unite(i[0], i[1])
    
    counter_dict = {}
    roots = []
    for i in range(N):
        roots.append((uf_road.root(i), uf_rail.root(i)))
        if roots[i] in counter_dict.keys():
            counter_dict[roots[i]] += 1
        else:
            counter_dict[roots[i]] = 1
    
    output = []
    for i in roots:
        output.append(counter_dict[i])

    print(' '.join(map(str, output)))

if __name__=='__main__':
    main()