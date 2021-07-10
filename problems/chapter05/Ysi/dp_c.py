def main():
    n = int(input())
    welfare = []
    for i in range(n):
        a, b, c = map(int, input().split())
        welfare.append([a, b, c])

    dp = [[0, 0, 0] for _ in range(n+1)]

    for i in range(1, n+1):
        dp[i][0] = max(dp[i-1][1] + welfare[i-1][0], dp[i-1][2] + welfare[i-1][0])
        dp[i][1] = max(dp[i-1][0] + welfare[i-1][1], dp[i-1][2] + welfare[i-1][1])
        dp[i][2] = max(dp[i-1][0] + welfare[i-1][2], dp[i-1][1] + welfare[i-1][2])

    ans = max(dp[n])
    print(ans)
if __name__=='__main__':
    main()