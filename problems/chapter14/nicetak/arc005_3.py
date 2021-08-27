from collections import deque

def main():
    H, W = map(int, input().split())
    mp = [input() for _ in range(H)]

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    x_s, y_s, x_g, y_g = -1, -1, -1, -1
    for i in range(H):
        for j in range(W):
            if mp[i][j] == "s":
                x_s, y_s = i, j
            elif mp[i][j] == "g":
                x_g, y_g = i, j
    
    que = deque()
    que.appendleft((x_s, y_s))
    dists = [[10**9] * W for _ in range(H)]
    dists[x_s][y_s] = 0

    while len(que) > 0:
        x, y = que.popleft()

        for d in range(4):
            x_new = x + dx[d]
            y_new = y + dy[d]

            if (x_new >=0) & (x_new < H) & (y_new >= 0) & (y_new < W):
                if mp[x_new][y_new] == "#":
                    if dists[x_new][y_new] > dists[x][y] + 1:
                        dists[x_new][y_new] = dists[x][y] + 1
                        que.append((x_new, y_new))
                else:
                    if dists[x_new][y_new] > dists[x][y]:
                        dists[x_new][y_new] = dists[x][y]
                        que.appendleft((x_new, y_new))

    if dists[x_g][y_g] <= 2:
        print("YES")
    else:
        print("NO")


if __name__=='__main__':
    main()
