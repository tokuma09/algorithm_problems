from itertools import accumulate 

def main():
    n = int(input())
    a = list(map(int, input().split()))

    dp=[[10**18 for i in range(n+1)] for j in range(n)]
    
    s = [0]
    for i in range(n):
        s.append(s[i] + a[i])


    for i in range(n):
        dp[i][i+1] = 0

    for i in range(n-2, -1, -1):
        for j in range(i+2, n+1):
            for k in range(i+1, j):
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (s[j] - s[i]))
    
    ans = dp[0][n]

    print(ans)
if __name__=='__main__':
    main()