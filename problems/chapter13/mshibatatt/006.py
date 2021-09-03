# find cycle in directed graph
# https://qiita.com/drken/items/a803d4fc4a727e02f7ba
import sys
sys.setrecursionlimit = 1000000

def dfs(G, n, seen, finished, path, pos):
    seen[n] = True
    path.append(n)
    for nxt in G[n]:
        if finished[nxt]:
            continue
        if seen[nxt] == True and finished[nxt] == False:
            pos = nxt
            return pos
        pos = dfs(G, nxt, seen, finished, path, pos)
        if pos != -1:
            return pos
    finished[n] = True
    path.pop()

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        G[a].append(b)

    seen = [False]*N
    finished = [False]*N
    output = 'No'
    path = []
    pos = -1

    while not all(seen):
        for i, e in enumerate(seen):
            if not e:
                node = i
                break
        
        pos = dfs(G, node, seen, finished, path, pos)
        if pos != -1:
            output = 'Yes'
            cycle = []
            top = path[-1]
            while len(path) > 0:
                t = path[-1]
                cycle.append(t)
                path.pop()
                if t == pos:
                    cycle.append(top)
                    break
            break

    if output == 'Yes':
        print(output, ' -> '.join(map(str, cycle)))
    else:
        print(output)

if __name__=='__main__':
    main()