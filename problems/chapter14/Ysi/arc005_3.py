def main():
    H, W = map(int, input().split())
    C = []
    for i in range(H):
        row = list(input())
        C.append(row)
    
    for i in range(H):
        for j in range(W):
            if C[i][j] == "s":
                sx = i
                sy = j
            if C[i][j] == "g":
                gx = i
                gy = j
    
    from collections import deque
    Q = deque()
    Q.append((sx, sy))
    dist = [[float("inf")] * W for _ in range(H)]
    dist[sx][sy] = 0
    
    while len(Q) > 0:
        i, j = Q.popleft()
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            next_i = i + dx
            next_j = j + dy
            if not ((0 <= next_i < H) and (0 <= next_j < W)):
                continue
            if dist[next_i][next_j] == float("inf"):
                if C[next_i][next_j] == ".":
                    dist[next_i][next_j] = min(dist[next_i][next_j], dist[i][j])
                    Q.appendleft((next_i, next_j))
                elif C[next_i][next_j] == "#":
                    dist[next_i][next_j] = min(dist[next_i][next_j],dist[i][j]+1)
                    Q.append((next_i, next_j))
                elif C[next_i][next_j] == "g":
                    dist[next_i][next_j] = min(dist[next_i][next_j],dist[i][j])

    if dist[gx][gy] <= 2:
        ans = "YES"
    else:
        ans = "NO"
    print(ans)
                
if __name__=='__main__':
    main()