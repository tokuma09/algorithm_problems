# https://atcoder.jp/contests/dp/tasks/dp_p
import sys
sys.setrecursionlimit(1000000)

def dfs(G, v, dp, seen, mod = 10**9 + 7):
    is_teminal = True
    for nxt in G[v]:
        if seen[nxt]:
            continue
        is_teminal = False
        seen[nxt] = True
        dfs(G, nxt, dp, seen, mod)
    
    if is_teminal:
        dp[0][v] = 1
        dp[1][v] = 1
        return
    
    black_case = 1
    white_case = 1
    for nxt in G[v]:
        if dp[0][nxt] == dp[1][nxt] == 0:
            continue 
        black_case *= dp[1][nxt]
        white_case *= dp[1][nxt] + dp[0][nxt]
    dp[0][v] = black_case % mod 
    dp[1][v] = white_case % mod 

def main():
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        x, y = map(int, input().split())
        x -= 1; y -= 1
        G[x].append(y)
        G[y].append(x)
    mod = 10**9 + 7

    # dp[0][i] is pattern of sub-tree when node-i is black
    # dp[1][i] is pattern of sub-tree when node-i is white 
    dp = [[0] * N for i in range(2)]
    seen = [False] * N
    seen[0] = True
    dfs(G, 0, dp, seen)

    print((dp[0][0] + dp[1][0]) % mod)

if __name__=='__main__':
    main()