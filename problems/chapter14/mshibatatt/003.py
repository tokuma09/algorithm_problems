# https://atcoder.jp/contests/abc132/tasks/abc132_e
import heapq

def dijkstra(G, s, method_heap = True):
    if method_heap:
        N = len(G)
        dist = [float('Inf')] * N
        dist[s] = 0
        heap = [(dist[s], s)]
        heapq.heapify(heap)
        
        while len(heap) > 0:
            d, v = heapq.heappop(heap)

            # ignore if d is not minmum
            if d > dist[v]:
                continue

            for e in G[v]:
                if dist[v] + 1 < dist[e]:
                    dist[e] = dist[v] + 1
                    heapq.heappush(heap, (dist[e], e))
        
        return dist

    else:
        N = len(G)
        dist = [float('Inf')] * N
        dist[s] = 0
        seen = [False] * N
        for _ in range(N):
            min_dist = float('Inf')
            
            min_v = -1
            for v in range(N):
                if not seen[v] and dist[v] < min_dist:
                    min_dist = dist[v]
                    min_v = v
            
            if min_v == -1:
                break
            
            seen[min_v] = True
            for e in G[min_v]:
                dist[e] = min(dist[min_v] + 1, dist[e])
        
        return dist

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, input().split())
        G[u-1].append(v-1)
    S, T = map(int, input().split())
    S -= 1
    T -= 1

    # If u -> v in G, u_t -> v_t+1 in G3 (t=0->1->2->0)
    G3 = [[] for _ in range(3*N)]
    for now in range(N):
        for nxt in G[now]:
            for i in range(3): 
                from_v = N * i + now
                to_v = N * ((i + 1)%3) + nxt
                G3[from_v].append(to_v)

    # Dijkstra to find shortest path
    dist = dijkstra(G3, S)

    if dist[T] == float('Inf'):
        output = -1
    else:
        output = dist[T]//3

    print(output)

if __name__=='__main__':
    main()