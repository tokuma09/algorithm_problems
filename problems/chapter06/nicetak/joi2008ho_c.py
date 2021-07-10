import bisect 

def main():
    N, M = map(int, input().split())
    ps = [int(input()) for _ in range(N)]

    ps.append(0)
    pars = [p1 + p2 for p1 in ps for p2 in ps]
    pars.sort()

    ans = 0
    for par in pars:
        if par <= M:
            idx_insert = bisect.bisect_left(pars, M-par) - 1
            tmp = par if idx_insert == -1 else par + pars[idx_insert]
            ans = max(ans, tmp)

    print(ans)

if __name__=='__main__':
    main()
