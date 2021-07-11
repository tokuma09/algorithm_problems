def main():
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    a.sort()
    b.sort()
    c.sort()

    output = 0

    for i in b:
        # binary search in a
        # a[left] < i 
        # a[right] >= i
        # return left + 1
        left, right = 0, N-1
        if a[left] >= i:
            counter = 0
        elif a[right] < i:
            counter = N
        else:
            while right - left > 1:
                mid = left + (right - left)//2
                if a[mid] >= i:
                    right = mid
                else:
                    left = mid
            counter = left + 1

        # binary search in c
        # c[left] <= i 
        # c[right] > i
        # return N - right
        left, right = 0, N-1
        if counter == 0 or c[right] <= i:
            counter = 0
        elif c[left] > i:
            counter = counter * N
        else:
            while right - left > 1:
                mid = left + (right - left)//2
                if c[mid] > i:
                    right = mid
                else:
                    left = mid
            counter = counter * (N - right)
        output += counter

    print(output)

if __name__=='__main__':
    main()
