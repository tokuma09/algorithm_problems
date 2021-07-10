def main():
    n, w = map(int, input().split())
    a = list(map(int, input().split()))
    
    dp = [[0] * (w+1) for i in range(n+1)]

    for i in range(n+1):
        dp[i][0] = 1

    for i in range(n):
        for j in range(w+1):
            if j - a[i] >= 0:
                dp[i+1][j] = dp[i][j] | dp[i][j - a[i]]
            else:
                dp[i+1][j] = dp[i][j]

    if dp[n][w]:
        ans = "Yes"
    else:
        ans = "No"
    print(ans)
if __name__=='__main__':
    main()