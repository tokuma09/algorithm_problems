def main():
    s = input()
    t = input()
    
    len_s = len(s)
    len_t = len(t)
    
    # dp[i][j] is m, where m is common substring with max length from s[0:i+1] and t[0:j+1]  
    # dp_len[i][j] is len(dp[i][j])
    dp_len = [[0]*len_t for i in range(len_s)]

    for i in range(len_s):
        for j in range(len_t):
            if (i == 0 or j == 0) and s[i] == t[j]:
                dp_len[i][j] = 1
            elif s[i] == t[j]:
                dp_len[i][j] = dp_len[i-1][j-1] + 1
            else:
                dp_len[i][j] = max(dp_len[i-1][j], dp_len[i][j-1])

    # restore substring 
    output = ''
    i, j = len_s-1, len_t-1
    counter = dp_len[i][j]
    while counter > 0:
        if dp_len[i][j] == dp_len[i-1][j] and i > 0:
            i -= 1
        elif dp_len[i][j] == dp_len[i][j-1] and j > 0:
            j -= 1
        else: 
            output = s[i] + output
            i -= 1
            j -= 1
            counter -= 1
    print(output)

if __name__=='__main__':
    main()