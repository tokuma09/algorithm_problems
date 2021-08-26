def get_mean_lr(l, r, acc_a):
    if l == 0:
        return acc_a[r] / (r + 1)
    else:
        return (acc_a[r] - acc_a[l-1]) / (r - l +1)

def main():
    import itertools
    N, M = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [[0] * M for _ in range(N)]
    acc_a = list(itertools.accumulate(a))
    
    for m in range(M):
        for n in range(N):
            if m == 0:
                dp[n][m] = get_mean_lr(0, n, acc_a)
            elif m > n:
                pass
            else:
                dp[n][m] = max([dp[n-x-1][m-1] + get_mean_lr(n-x, n, acc_a) for x in range(n-m+1)])
        
    print(dp[N-1][M-1])
    
if __name__=='__main__':
    main()
    