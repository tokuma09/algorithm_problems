# https://atcoder.jp/contests/arc005/tasks/arc005_3
from collections import deque

def main():
    H, W = map(int, input().split())
    G = []
    for i in range(H):
        line = input()
        for j, e in enumerate(line):
            if e == 's':
                start = (i, j)
        G.append(line)

    que = deque([start])
    seen = [[False]*W for _ in range(H)]
    breaks = [[float('inf')]*W for _ in range(H)]
    seen[que[0][0]][que[0][1]] = True
    breaks[que[0][0]][que[0][1]] = 0

    while len(que) > 0:
        x, y = que.popleft()
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            nx = x + dx
            ny = y + dy
            if not (0 <= nx <= H-1 and 0 <= ny <= W-1):
                continue
            if seen[nx][ny]:
                continue

            if G[nx][ny] == '.':
                seen[nx][ny] = True
                que.appendleft((nx, ny))
                breaks[nx][ny] = min(breaks[nx][ny], breaks[x][y])
            elif G[nx][ny] == '#':
                seen[nx][ny] = True
                que.append((nx, ny))
                breaks[nx][ny] = min(breaks[nx][ny], breaks[x][y] + 1)
            elif G[nx][ny] == 'g':
                if breaks[x][y] <= 2:
                    output = 'YES'
                else:
                    output = 'NO'
                que = deque([])
                break

    print(output)

if __name__=='__main__':
    main()
        






