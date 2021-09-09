def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a,b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)

    import sys
    sys.setrecursionlimit(500*500)
    visited = [False]*N
    order = []
    def dfs(v):
        if visited[v] == True:
            return
        
        visited[v] = True
        for u in G[v]:
            dfs(u)
        
        order.append(v)
    
    for i in range(N):
        if visited[i]:
            continue
        dfs(i)
    order.reverse()

    dp=[0] * N

    for v in order:
        for v_next in G[v]:
            dp[v_next] = max(dp[v_next], dp[v]+1)
    ans = max(dp)
    print(ans)
if __name__=='__main__':
    main()