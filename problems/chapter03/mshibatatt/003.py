
def main():
    N = input()
    s = list(map(int, input().split()))

    output = float('inf')
    min_v = float('inf')

    for i in s:
        if i < min_v:
            output = min_v
            min_v = i
        elif i < output:
            output = i
    
    print(output)

if __name__=='__main__':
    main()


