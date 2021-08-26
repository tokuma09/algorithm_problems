def main():
    n, v = map(int, input().split())
    a = list(map(int, input().split()))

    count = 0
    for i in range(n):
        if a[i] == v:
            count += 1
    
    print(count)

if __name__=='__main__':
    main()