# https://atcoder.jp/contests/dp/tasks/dp_g

# dfs for topological sort
def dfs(G, n, seen, sort_list):
    for nxt in G[n]:
        if seen[nxt]:
            continue
        seen[nxt] = True
        dfs(G, nxt, seen, sort_list)
    sort_list.append(n)

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        x, y = map(int, input().split())
        G[x-1].append(y-1)

    # topological sort
    sort_list = []
    seen = [False] * N

    for i, e in enumerate(seen):
        if e:
            continue
        seen[i] = True
        dfs(G, i, seen, sort_list)

    sort_list = sort_list[::-1]

    # dp[i] is max length path to reach node i
    dp = [0] * N
    for now in sort_list:
        for nxt in G[now]:
            dp[nxt] = max(dp[nxt], dp[now] + 1)

    output = max(dp)
    print(output)

if __name__=='__main__':
    main()
