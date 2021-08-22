# https://atcoder.jp/contests/abc061/tasks/abc061_d

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b, c = map(int, input().split())
        G[a-1].append([b-1, c])
    
    dist = [-float('Inf')] * N
    dist[0] = 0
    exist_positive_cycle = False
    for i in range(N):
        update = False
        for v in range(N):
            if dist[v] == -float('Inf'):
                continue
            for nxt, w in G[v]:
                if dist[nxt] < dist[v] + w:
                    dist[nxt] = dist[v] +w
                    update = True
        if not update:
            break
        if i == N-1 and update:
            exist_positive_cycle = True

    if exist_positive_cycle:
        print('inf')
    else:
        print(dist[-1])

if __name__=='__main__':
    main()

