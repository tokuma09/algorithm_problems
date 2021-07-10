def main():
    n = int(input())
    p = list(map(int, input().split()))
    w = sum(p)    
    dp = [[0 for i in range(w+1)] for j in range(n+1)]
    
    for i in range(n+1):
        dp[i][0] = 1

    for i in range(1, n+1):
        for j in range(1, w+1):
            if j - p[i-1] >= 0:
                if dp[i-1][j-p[i-1]] == 1 or dp[i-1][j] == 1:
                    dp[i][j] = 1
            else:
                if dp[i-1][j] == 1:
                    dp[i][j] = 1
            
    ans = []
    for j in range(w+1):
        if dp[n][j] == 1:
            ans.append(j)

    print(len(ans))
if __name__=='__main__':
    main()