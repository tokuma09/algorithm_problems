from itertools import accumulate
class Bit():
    def __init__(self, n) -> None:
        self.size = n
        self.tree = [0] * (n + 1)
    
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

def main():
    N = int(input())
    a = list(map(int, input().split()))
    A = max(a)
    M = (N*(N+1)) // 4 + 1
    

    def is_ok(mid):
        res = [0] + [1 if x < mid else -1 for x in a]
        bit = Bit(2*N+2)
        qusai_inv = 0

        for i, e in enumerate(accumulate(res)):
            bit.add(e+N+1, 1)
            qusai_inv += bit.sum(e+N)
            
        if qusai_inv < M:
            return True
        else:
            return False


    def bisect(ng, ok):
        while (abs(ok - ng) > 1):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
    ans = bisect(A+1, 1)
    print(ans)
if __name__=='__main__':
    main()