def main():
    n, w = map(int, input().split())
    a = list(map(int, input().split()))
    m = list(map(int, input().split()))

    dp=[[-1 for i in range(w+1)] for j in range(n+1)]
    dp[0][0] = 0
    
    for i in range(n):
        for j in range(w+1):
            if dp[i][j] >= 0:
                dp[i+1][j] = m[i]
            elif j >= a[i] and dp[i+1][j-a[i]] > 0:
                dp[i+1][j] = dp[i+1][j - a[i]] - 1
            else:
                dp[i+1][j] = -1
            
    if dp[n][w]>=0:
        ans = "Yes"
    else:
        ans = "No"

    print(ans)
if __name__=='__main__':
    main()



