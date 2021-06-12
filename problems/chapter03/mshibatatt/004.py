
def main():
    N = input()
    s = list(map(int, input().split()))
    min_v = float('inf')
    max_v = - float('inf')

    for i in range(s):
        if i < min_v:
            min_v = i
        if i > max_v:
            max_v = i
    
    print(max_v - min_v)

if __name__=='__main__':
    main()