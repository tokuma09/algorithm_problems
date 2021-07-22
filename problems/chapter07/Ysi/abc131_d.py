def main():
    N = int(input())
    t = []
    for _ in range(N):
        a,b = map(int, input().split())
        t.append([a, b])
    
    ts = sorted(t, key=lambda x: x[1])
    
    ans = 0
    last = 0
    for i in range(N):
        a, b = ts[i]
        if last + a <= b:
            ans += 1
            last = last + a
    if ans == N:
        ans = "Yes"
    else:
        ans = "No"
    print(ans)
if __name__=='__main__':
    main()
