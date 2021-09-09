def main():
    N,M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
    
    S, T = map(int, input().split())
    S -= 1
    T -= 1
    
    from collections import deque
    Q = deque()
    Q.append((S, 0))
    dist = [[-1] * 3 for _ in range(N)]
    dist[S][0] = 0
    
    while len(Q) > 0:
        v, n = Q.popleft()
        for v_next in G[v]:
            nn = (n+1)%3

            if dist[v_next][nn] != -1:
                continue

            dist[v_next][nn] = dist[v][n] + 1
            Q.append((v_next, nn))

    ans = dist[T][0] // 3
    if ans < 0:
        ans = -1
    print(ans)
if __name__=='__main__':
    main()