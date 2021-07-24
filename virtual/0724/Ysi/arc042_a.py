from collections import deque
def main():
    N, M = map(int, input().split())
    a = []
    for _ in range(M):
        a.append(int(input()))

    base = deque()
    for i in range(N, 0, -1):
        base.append(i)
        
    for i in range(M):
        base.append(a[i])

    flag = set()
    while(len(flag) < N):
        x = base.pop()
        if x in flag:
            continue
        else:
            flag.add(x)
            print(x)


if __name__=='__main__':
    main()