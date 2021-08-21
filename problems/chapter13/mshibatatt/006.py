# find cycle in directed graph

def dfs(G, n, seen, path):
    path.append(n)
    for nxt in G[n]:
        if nxt in path:
            path.append(nxt)
            return path
        if seen[nxt]:
            continue
        seen[nxt] = True
        return dfs(G, nxt, seen, path)

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)

    seen = [False]*N
    output = 'No'

    while not all(seen):
        for i, e in enumerate(seen):
            if not e:
                node = i
                break
        seen[node] = True
        cycle = dfs(G, node, seen, [])
        if cycle != None:
            output = 'Yes'
            break

    if output == 'Yes':
        print(output, ' -> '.join(map(str, cycle)))
    else:
        print(output)

if __name__=='__main__':
    main()