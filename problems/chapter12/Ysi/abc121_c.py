def main():
    N, M = map(int, input().split())
    ab = []
    for _ in range(N):
        a, b = map(int, input().split())
        ab.append([a, b])

    ab_sorted = sorted(ab, key=lambda x: x[0])
    
    num = M
    ans = 0
    for i in range(N):
        a, b = ab_sorted[i]
        if num > b:
            num -= b
            ans += a*b
        else:
            ans += a*num
            num = 0
    
    print(ans)

if __name__=='__main__':
    main()