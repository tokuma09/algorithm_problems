from collections import deque

def main():
    K = int(input())

    G = [[] for _ in range(K)]
    for i in range(K):
        G[i].append([(i+1)%K, 1])
        G[i].append([(i*10)%K, 0])

    que = deque([1])
    dist = [float('inf')] * K
    dist[1] = 1

    while len(que) > 0:
        i = que.popleft()
        for j, c in G[i]:
            if dist[i] + c < dist[j]:
                dist[j] = dist[i] + c
                if c == 1:
                    que.append(j)
                elif c == 0: 
                    que.appendleft(j)

    print(dist[0])

if __name__=='__main__':
    main()  