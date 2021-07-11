def less_than_k(x, a, b, N, k):
    # fix a and binary search in b
    # count number of a * b < x
    # return True if count < k otherwise False
    counter = 0
    for i in a:
        left = 0
        right = N-1
        if i * b[0] >= x:
            continue
        if i * b[N-1] < x:
            counter += N
            continue
        while right - left > 1:
            mid = left + (right - left)//2
            if i * b[mid] < x:
                left = mid
            else:
                right = mid
        counter += right
        if counter >= k:
            return False
    return True

def main():
    N, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    left = 0
    right = a[-1]*b[-1]

    while right - left > 1:
        mid = left + (right - left)//2
        if less_than_k(mid, a, b, N, k):
            left = mid
        else:
            right = mid

    print(left)

if __name__=='__main__':
    main()