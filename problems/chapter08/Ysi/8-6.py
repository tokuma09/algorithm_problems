def main():
    N,M = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    res = dict()
    for i in range(N):
        ai = a[i]
        if not ai in res:
            res[ai] = [1, 0]
        else:
            res[a[i]][0] += 1
    
    for j in range(M):
        bj = b[j]
        if not bj in res:
            res[bj] = [0, 1]
        else:
            res[bj][1] += 1
    
    ans = 0
    for val in res.values():
        ans += val[0] * val[1]
    print(ans)
if __name__=='__main__':
    main()