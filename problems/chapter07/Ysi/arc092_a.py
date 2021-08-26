def main():
    N = int(input())
    red = []
    for _ in range(N):
        a, b = map(int, input().split())
        red.append([a, b])
    
    blue = []
    for _ in range(N):
        c, d = map(int, input().split())
        blue.append([c, d])
    
    rs = sorted(red, reverse=True, key=lambda x: x[1])
    bs = sorted(blue, key=lambda x: x[0])
    ans = 0
    matched = [False]*N
    for b in bs:
        for i, r in enumerate(rs):
            if r[0] < b[0] and r[1] < b[1] and not matched[i]:
                ans += 1
                matched[i] = True
                break 
        
    print(ans)
if __name__=='__main__':
    main()