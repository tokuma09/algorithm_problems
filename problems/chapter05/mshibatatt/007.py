def main():
    s = input()
    t = input()
    
    len_s = len(s)
    len_t = len(t)

    # dp[i][j] is m, where m is common substring with max length from s[0:i+1] and t[0:j+1]  
    dp = [[None]*len_t for i in range(len_s)]
    # dp_len[i][j] is len(dp[i][j])
    dp_len = [[None]*len_t for i in range(len_s)]

    for i in range(len_s):
        for j in range(len_t):
            if i == 0 and j == 0:
                dp[i][j] = s[i] if s[i] == t[j] else ''
                dp_len[i][j] = 1 if s[i] == t[j] else 0
            elif i == 0:
                dp[i][j] = s[i] if s[i] == t[j] or dp[i][j-1] == s[i] else ''
                dp_len[i][j] = 1 if s[i] == t[j] or dp[i][j-1] == s[i] else 0
            elif j == 0:
                dp[i][j] = t[j] if s[i] == t[j] or dp[i-1][j] == t[j] else ''
                dp_len[i][j] = 1 if s[i] == t[j] or dp[i-1][j] == t[j] else 0
            else:
                if s[i] == t[j]:
                    dp[i][j] = dp[i-1][j-1] + s[i]
                    dp_len[i][j] = dp_len[i-1][j-1] + 1
                elif dp_len[i-1][j] >= dp_len[i][j-1]:
                    dp[i][j] = dp[i-1][j]
                    dp_len[i][j] = dp_len[i-1][j]
                else:
                    dp[i][j] = dp[i][j-1]
                    dp_len[i][j] = dp_len[i][j-1]
    
    print(dp[len_s-1][len_t-1])

if __name__=='__main__':
    main()