def main():
    N, K = map(int, input().split())

    res = []
    for x in range(2, 2*N+1):
        y = x - K
        if 2 <= y <= 2*N:
            res.append([x,y])
    ans = 0
    for i in range(len(res)):
        x, y = res[i]
        if x <= N + 1:
            f = x-1
        else:
            f = (2*N + 1) - x
        if y <= N + 1:
            l = y-1
        else:
            l = (2*N + 1) - y
        ans += f * l
    print(ans)
if __name__=='__main__':
    main()