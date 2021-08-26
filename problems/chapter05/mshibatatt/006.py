def main():
    N, W = map(int, input().split())
    a = list(map(int, input().split()))
    m = list(map(int, input().split()))

    # dp[i][j] is k if you can make j+1 from a0,...,ai, with with using k times ai, 
    #  None if you can't make it
    dp = [[None]*W for i in range(N)]

    for i in range(N):
        for j in range(W):
            if i == 0 and j == 0:
                if (j+1) == a[i]:
                    dp[i][j] == 1
                elif dp[i][j-a[i]] != None and dp[i][j-a[i]] < m[i]:
                    dp[i][j] = dp[i][j-a[i]] + 1
            else:
                temp = []
                if j + 1 == a[i] or (j > a[i] and dp[i-1][j-a[i]] != None):
                    temp.append(1)
                if dp[i-1][j] != None:
                    temp.append(0)
                if j > a[i] and dp[i][j-a[i]] != None and dp[i][j-a[i]] < m[i]:
                    temp.append(dp[i][j-a[i]] + 1)
                
                dp[i][j] = min(temp) if len(temp) > 0 else None
    
    output = "Yes" if dp[N-1][W-1] != None else "No"          
    print(output)

if __name__=='__main__':
    main()