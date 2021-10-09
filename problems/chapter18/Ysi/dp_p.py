def main():
    N = int(input())
    MOD = 10 ** 9 + 7
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        G[x].append(y)
        G[y].append(x)
    
    black=[1 for _ in range(N)]
    white=[1 for _ in range(N)]

    import sys
    sys.setrecursionlimit(500*500)
    def dfs(v, p = -1):
        for ch in G[v]:
            if ch == p:
                continue
            dfs(ch, v)

        for ch in G[v]:
            if ch == p:
                continue
            black[v] = (black[v]*white[ch]) % MOD
            white[v] = (white[v]*(black[ch]+white[ch])) % MOD

    dfs(0)
    ans = (black[0]+white[0])%MOD
    print(ans)
if __name__=='__main__':
    main()