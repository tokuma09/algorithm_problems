# https://atcoder.jp/contests/abc007/tasks/abc007_3
from collections import deque

def main():
    H, W = map(int, input().split())
    sx, sy = map(int, input().split())
    gx, gy = map(int, input().split())
    sx -= 1; sy -= 1; gx -= 1; gy -= 1

    G = []
    for _ in range(H):
        G.append(input())

    todo = deque()
    todo.append([sx, sy])
    distance = [[float('Inf')]*W for _ in range(H)]
    distance[sx][sy] = 0

    while len(todo) > 0:
        x, y = todo.popleft()
        for nx, ny in zip([x, x, x+1, x-1], [y-1, y+1, y, y]):
            if 0 <= nx < H and 0 <= ny < W and distance[nx][ny] == float('Inf'):
                if G[nx][ny] == '.':
                    distance[nx][ny] = min(distance[x][y] + 1, distance[nx][ny])
                    todo.append([nx, ny])

    output = distance[gx][gy]
    if output == float('Inf'):
        print('No')
    else:
        print(output)

if __name__=='__main__':
    main()