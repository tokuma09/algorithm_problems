def main():
    N, M = map(int, input().split())
    a = list(map(int, input().split()))

    # dp[i][j] is optimal weighted sum when you make j partitions for a0,...,ai
    dp = [[-float('Inf')]*M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if j == 0:
                dp[i][j] = sum(a[0:i+1])/(i+1)
            else:
                for k in range(i):
                    dp[i][j] = max(dp[i][j], dp[k][j-1] +  sum(a[k+1:i+1])/(i-k) )
    
    print(dp[-1][-1])

if __name__=='__main__':
    main()
