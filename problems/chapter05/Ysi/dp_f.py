def main():
    s = list(input())
    t = list(input())

    dp=[["" for i in range(len(t)+1)] for j in range(len(s)+1)]
    
    for i in range(1, len(s)+1):
            for j in range(1,len(t)+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + s[i-1]
                else:
                    if len(dp[i-1][j]) > len(dp[i][j-1]):
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i][j-1]

    ans = dp[len(s)][len(t)]

    print(ans)
if __name__=='__main__':
    main()