def main():
    N, W = map(int, input().split())
    a =list(map(int, input().split()))

    # dp[i][j] is "Yes" if you can make j+1 from a0,...,ai, with any times otherwise "No"
    dp = [[None]*W for i in range(N)]

    for i in range(N):
        for j in range(W):
            if i == 0:
                dp[i][j] = "Yes" if (j+1) % a[i] == 0 else "No"
            else:
                dp[i][j] = "Yes" if (j+1) % a[i] == 0 or \
                                    dp[i-1][j] == "Yes" or \
                                    (j > a[i] and dp[i-1][j-a[i]] == "Yes") or \
                                    (j > a[i] and dp[i][j-a[i]] == "Yes") \
                                else "No"
    print(dp[N-1][W-1])

if __name__=='__main__':
    main()