def main():
    N, M = map(int, input().split())
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    
    output = 0
    if N <= M:
        for i in a:
            if i in b:
                output += 1
                b.remove(i)
    else:
        for j in b:
            if j in a:
                output += 1
                a.remove(j)


    print(output)

if __name__=='__main__':
    main()
    