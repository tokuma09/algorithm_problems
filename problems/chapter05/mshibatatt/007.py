def chmaxlen(a, b):
    if len(a) >= len(b):
        return a
    else: return b

def main():
    s = input()
    t = input()
    
    len_s = len(s)
    len_t = len(t)

    # dp[i][j] is m, where m is common substring with max length from s[0:i+1] and t[0:j+1]  
    dp = [[None]*len_t for i in range(len_s)]

    for i in range(len_s):
        for j in range(len_t):
            if i == 0 and j == 0:
                dp[i][j] = s[i] if s[i] == t[j] else ''
            elif i == 0:
                dp[i][j] = s[i] if s[i] == t[j] or dp[i][j-1] == s[i] else ''
            elif j == 0:
                dp[i][j] = t[j] if s[i] == t[j] or dp[i-1][j] == t[j] else ''
            else:
                dp[i][j] = dp[i-1][j-1] + s[i] if s[i] == t[j] \
                     else chmaxlen(dp[i-1][j], dp[i][j-1])
    
    print(dp[len_s-1][len_t-1])

if __name__=='__main__':
    main()