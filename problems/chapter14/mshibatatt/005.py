# https://atcoder.jp/contests/arc084/tasks/arc084_b
from collections import deque

def main():
    K = int(input())

    # create path of mod K
    # w: 1 -> add 1
    # w: 0 -> mutiply 10
    G = [[] for _ in range(K)]
    for i in range(K):
        G[i].append([(i+1)%K, 1])
        G[i].append([(i*10)%K, 0])

    # 0-1bfs
    que = deque([1])
    dp = [float('inf')] * K
    dp[1] = 1

    while len(que) > 0:
        now = que.popleft()
        for nxt, w in G[now]:
            if dp[now] + w < dp[nxt]:
                dp[nxt] = dp[now] + w
                if w == 1:
                    que.append(nxt)
                elif w == 0: 
                    que.appendleft(nxt)

    print(dp[0])

if __name__=='__main__':
    main()  
