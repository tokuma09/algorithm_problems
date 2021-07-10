def main():
    N = int(input())
    u = []
    for i in range(N):
        utility = list(map(int, input().split()))
        u.append(utility)
    
    # i日目にjを選んだ場合の最大幸福度
    dp = [[0] * 3 for i in range(N)]

    for i in range(N):
        if i == 0:
            for j in range(3):
                dp[i][j] = u[i][j]
        else:
            for j in range(3):
                dp[i][j] = u[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])
    
    print(max(dp[N-1]))

if __name__=='__main__':
    main()
