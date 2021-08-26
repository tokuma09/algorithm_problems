# https://atcoder.jp/contests/abc121/tasks/abc121_c

def main():
    N, M = map(int, input().split())
    stores = []
    for _ in range(N):
        stores.append(list(map(int, input().split())))

    stores.sort()
    output = 0
    counter = 0
    i = 0
    while counter < M:
        output += stores[i][0] * min(stores[i][1], M - counter)
        counter += stores[i][1]
        i += 1

    print(output)

if __name__=='__main__':
    main()