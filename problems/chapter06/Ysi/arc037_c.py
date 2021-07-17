from bisect import bisect_right
def main():
    N, K = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    C = a[-1] * b[-1]

    def is_ok(mid):
        count = 0
        for i in range(N):
            ai = a[i]
            j = bisect_right(b, mid // ai)
            count += j
            
        if count >= K:
            res = True
        else:
            res = False
        return res
    
    def bisect(ng, ok):
        while (abs(ok - ng) > 1):
            mid = (ok + ng) // 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
        return ok
    
    ans = bisect(-1, C+1)

    print(ans)
if __name__=='__main__':
    main()