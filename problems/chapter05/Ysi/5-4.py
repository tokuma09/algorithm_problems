def main():
    n, w, k = map(int, input().split())
    a = list(map(int, input().split()))

    dp = [[-1 for i in range(w+1)] for j in range(n+1)]

    for i in range(n):
        if a[i] <= w:
            dp[1][a[i]] = 1

    for i in range(n):
        for j in range(w+1):
            if j - a[i] >= 0:
                if dp[i][j] > 0 and dp[i][j - a[i]] > 0:
                    dp[i+1][j] = min(dp[i][j],dp[i][j - a[i]] + 1)
                elif dp[i][j] > 0:
                    dp[i+1][j] = dp[i][j]
                elif dp[i][j - a[i]] > 0:
                    dp[i+1][j] = dp[i][j - a[i]] + 1
            else:
                if dp[i][j] > 0:
                    dp[i+1][j] = dp[i][j]

    if 0 < dp[n][w] <= k:
        ans = "Yes"
    else:
        ans = "No"
    print(ans)
if __name__=='__main__':
    main()