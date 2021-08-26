def main():
    N,M = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    res = dict()
    for i in range(N):
        ai = a[i]
        if ai in res:
            res[ai] += 1
        else:
            res[a[i]] = 1
    
    for j in range(M):
        bj = b[j]
        if bj in res:
            res[bj] += 1
        else:
            res[bj] = 1
    ans = 0
    for val in res.values():
        if val > 1:
            ans += 1

    print(ans)
if __name__=='__main__':
    main()