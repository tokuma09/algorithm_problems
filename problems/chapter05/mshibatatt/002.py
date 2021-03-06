def main():
    N, W = map(int, input().split())
    a = list(map(int, input().split()))

    # dp[i][j] is "Yes" if you can make j+1 from a0,...,ai else "No" 
    dp = [[None]*W for i in range(N)]

    for i in range(N):
        for j in range(W): # regard 0:(W-1) as 1:W
            if i == 0:
                dp[i][j] = "Yes" if j+1 == a[i] else "No"
            
            else:
                dp[i][j] = "Yes" if dp[i-1][j] == "Yes" or \
                                (a[i] < j and dp[i-1][j-a[i]] == "Yes") or \
                                (a[i] == j+1) \
                              else "No"
    
    print(dp[N-1][W-1])

if __name__=='__main__':
    main()
