def main():
    N, M = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    output = 0
    count = {}

    for i in a:
        if i in count.keys():
            count[i] += 1
        else:
            count[i] = 1
    for j in b:
        if j in count.keys():
            output += count[j]  

    print(output)

if __name__=='__main__':
    main()
    