def has_bit(n, i):
    return (n & (1 << i) > 0)

def main():
    s = list(input())
    
    ans = 0
    for i in range(2**(len(s)-1)):
        lastInserted = 0
        for j in range(len(s)-1):
            if has_bit(i, j):
                ans += int(''.join(s[lastInserted:j+1]))
                lastInserted = j+1
        if lastInserted < len(s):
            ans += int(''.join(s[lastInserted:len(s)]))
    print(ans)

if __name__=='__main__':
    main()