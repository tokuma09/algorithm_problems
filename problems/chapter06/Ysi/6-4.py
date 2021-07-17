def main():
    N, M = map(int, input().split())
    a = list(map(int, input().split()))
    A = a[-1]

    def is_ok(mid):
        last = a[0]
        count = 1
        
        for i in range(1,N):
            if a[i] - last >= mid:
                count += 1
                last = a[i]
        
        if count >= M:
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

    ans = bisect(A, 0)

    print(ans)
if __name__=='__main__':
    main()