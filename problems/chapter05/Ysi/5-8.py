def main():
    n, m = map(int, input().split())
    a  = list(map(int, input().split()))

    dp=[[0 for i in range(m)] for j in range(n)]

    for i in range(n):
        for j in range(m):
            if j == 0:
                dp[i][j] = sum(a[0:i+1])/(i+1)
            else:
                for k in range(i):
                    dp[i][j] = max(dp[i][j], dp[k][j-1] +  sum(a[k+1:i+1])/(i-k))

    ans = dp[n-1][m-1]  
    print(ans)
if __name__=='__main__':
    main()