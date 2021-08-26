def main():
    n = int(input())
    a = list(map(int, input().split()))

    min = 100000000000
    ans = 100000000001
    for i in range(n):
        if a[i] < min:
            ans = min
            min = a[i]
        elif a[i] < ans:
            ans = a[i]

    print(ans)

if __name__=='__main__':
    main()