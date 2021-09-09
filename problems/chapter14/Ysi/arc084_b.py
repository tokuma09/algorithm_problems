def main():
    K = int(input())


    from heapq import heappush, heappop
    G = [[] for _ in range(K)]
    for i in range(K):
        G[i].append([(i+1)%K, 1])
        G[i].append([(i*10)%K, 0])

    def dijkstra(s, n): # (始点, ノード数)
        dist = [-1] * n
        hq = [(0, s)] # (distance, node)
        dist[s] =  1
        done = [False] * n # ノードが確定済みかどうか
        while hq:
            i = heappop(hq)[1] # ノードを pop する
            if done[i]:
                continue
    
            done[i] = True
            for j, c in G[i]: # ノード i に隣接しているノードに対して
                if dist[j] == -1 or dist[i] + c < dist[j]:
                    dist[j] = dist[i] + c
                    heappush(hq, (dist[j], j))
        return dist


    ans = dijkstra(1, K)[0]
    
    print(ans)
if __name__=='__main__':
    main()