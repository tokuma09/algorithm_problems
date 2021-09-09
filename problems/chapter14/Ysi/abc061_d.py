def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append((b, -c))
    
    INF = float("inf")
    dist = [INF]*N
    dist[0] = 0
    negative_cycle = False
    for i in range(N):
        update = False
        for a in range(N):
            if dist[a] == INF:
                continue
            for b,c in G[a]:
                if dist[b] > dist[a] + c:
                    dist[b] = dist[a] + c
                    update = True
                
                if b == N-1 and i == N-1:
                    negative_cycle = True

        if not update:
            continue
        
    
    if negative_cycle:
        ans = "inf"
    else:
        ans = -dist[N-1]

    print(ans)
if __name__=='__main__':
    main()