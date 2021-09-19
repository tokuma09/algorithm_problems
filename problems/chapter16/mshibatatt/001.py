# https://atcoder.jp/contests/abc010/tasks/abc010_4
import sys
sys.setrecursionlimit = 10000

def dfs(G, now, g, path, seen):
    for i, nxt in enumerate(G[now]):
        if seen[nxt['to']] or nxt['weight'] == 0:
            continue
        if nxt['to'] == g:
            path.append([now, i])
            return path
        seen[nxt['to']] = True
        path.append([now, i])
        ret_path = dfs(G, nxt['to'], g, path, seen)
        if ret_path is not None:
            return ret_path

def add_edge(G, v_from, v_to, w):
    content =  {'to': v_to,
                'rev': len(G[v_to]),
                'weight': w
                }
    content_rev =  {'to': v_from,
                    'rev': len(G[v_from]),
                    'weight': 0
                    }
    G[v_from].append(content)
    G[v_to].append(content_rev)

def get_residual(G, path, flow):
    for i, j in path:
        G[i][j]['weight'] -= flow
        G[G[i][j]['to']][G[i][j]['rev']]['weight'] += flow
    return G

def main():
    N, G, E = map(int, input().split())
    girls = list(map(int, input().split()))
    SNS = [[] for _ in range(N+1)]
    for _ in range(E):
        a, b = map(int, input().split())
        add_edge(SNS, a, b, 1)
        add_edge(SNS, b, a, 1)
    for i in girls:
        add_edge(SNS, i, N, 1)
    
    # calculate edge-connectivity
    output = 0
    SNS_residual = SNS.copy()
    while True:
        seen = [False]*(2*N)
        seen[0] = True
        path = dfs(SNS_residual, 0, N, [], seen)
        if path is None:
            break
        SNS_residual = get_residual(SNS_residual, path, 1)
        output += 1
    
    print(output)

if __name__=='__main__':
    main()