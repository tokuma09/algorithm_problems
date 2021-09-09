def main():
    K = int(input())


    from heapq import heappush, heappop
    G = [[] for _ in range(K)]
    for i in range(K):
        G[i].append([(i+1)%K, 1])
        G[i].append([(i*10)%K, 0])

    def dijkstra(s, n): # (�n�_, �m�[�h��)
        dist = [-1] * n
        hq = [(0, s)] # (distance, node)
        dist[s] =  1
        done = [False] * n # �m�[�h���m��ς݂��ǂ���
        while hq:
            i = heappop(hq)[1] # �m�[�h�� pop ����
            if done[i]:
                continue
    
            done[i] = True
            for j, c in G[i]: # �m�[�h i �ɗאڂ��Ă���m�[�h�ɑ΂���
                if dist[j] == -1 or dist[i] + c < dist[j]:
                    dist[j] = dist[i] + c
                    heappush(hq, (dist[j], j))
        return dist


    ans = dijkstra(1, K)[0]
    
    print(ans)
if __name__=='__main__':
    main()