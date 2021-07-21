from bisect import bisect_left

def main():
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    output = 0
    for i in b:
        output += bisect_left(i, a)

    print(output)

if __name__=='__main__':
    main()