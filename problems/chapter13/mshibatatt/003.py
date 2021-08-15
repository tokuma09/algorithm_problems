# https://atcoder.jp/contests/abc126/tasks/abc126_d

from collections import deque

def main():
    N = int(input())
    G = [{} for _ in range(N)]
    for _ in range(N-1):
        a, b, w = map(int, input().split())
        a -= 1
        b -= 1
        G[a][b] = w
        G[b][a] = w

    seen = [False]*N
    todo = deque([])
    color = [0]*N

    todo.append(0)
    while len(todo) > 0:
        now = todo.popleft()
        for nxt in G[now].keys():
            if seen[nxt]:
                if (G[now][nxt] % 2 == 0 and color[now] == color[nxt]) or \
                    (G[now][nxt] % 2 == 1 and color[now] != color[nxt]):
                    continue
                else:
                    print('Impossible')
                    break
            else:
                seen[nxt] = True
                todo.append(nxt)
                if G[now][nxt] % 2 == 0:
                    color[nxt] = color[now]
                else:
                    color[nxt] = 1 - color[now]

    for i in color:
        print(i)

if __name__=='__main__':
    main()

