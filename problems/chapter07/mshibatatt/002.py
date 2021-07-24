# https://atcoder.jp/contests/arc092/tasks/arc092_a
 
def main():
    N = int(input())
    red = []
    blue = []
    for _ in range(N):
        red.append(list(map(int, input().split())))
    for _ in range(N):
        blue.append(list(map(int, input().split())))
    
    # sort desc by y
    red.sort(key=lambda x: x[1], reverse=True)
    # sort by x
    blue.sort()
    
    output = 0
    matched_red = [False]*N
    for i in blue:
        for n, j in enumerate(red):
            if j[0] < i[0] and j[1] < i[1] and not matched_red[n]:
                output += 1
                matched_red[n] = True
                break

    print(output)

if __name__=='__main__':
    main()