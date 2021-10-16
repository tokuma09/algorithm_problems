def dfs(G, v, stable_set, seen):
    exist = False
    for child in G[v]:
        if not seen[child]:
            seen[child] = True
            dfs(G, child, stable_set, seen)
        if stable_set[child]:
            exist = True
    if not exist:
        stable_set[v] = True

def main():
    N = int(input())
    G = [[] for _ in range(N)]
    for _ in range(N-1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append(v)
        G[v].append(u)
    
    stable_set = [False]*N
    seen = [False]*N
    seen[0] = True
    dfs(G, 0, stable_set, seen)
    
    #print(stable_set)
    print(sum(stable_set))

if __name__=='__main__':
    main()

