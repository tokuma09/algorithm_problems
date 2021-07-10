from itertools import accumulate
 
def main():
    N = int(input())
    a = list(map(int, input().split()))
    cumsum = [0] + list(accumulate(a))
 
    # dp[i][j] is min sum cost of fusion in [i, j)
    dp = [[float('inf')]*(N+1) for _ in range(N)]
   
    for i in range(N - 1, -1, -1):
        dp[i][i + 1] = 0
        for j in range(i, N + 1):
            for k in range(i, j):
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+cumsum[j]-cumsum[i])
 
    print(dp[0][N])
 
if __name__=='__main__':
    main()