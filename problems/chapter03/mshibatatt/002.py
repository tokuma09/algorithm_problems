
def main():
    N, v = map(int, input().split())
    s = list(map(int, input().split()))
    
    output = 0

    for i in s:
        if i == v:
            output += 1
    
    print(output)


if __name__=='__main__':
    main()