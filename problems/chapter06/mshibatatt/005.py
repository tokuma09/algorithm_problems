# https://atcoder.jp/contests/arc037/tasks/arc037_c

import bisect

def less_than_k(x, a, b, k):
    # fix a and binary search in b
    # count number of a * b < x
    # return True if count < k otherwise False
    counter = 0
    for i in a:
        counter += bisect.bisect_right(b, x//i)
        if counter >= k:
            return True
    return False

def main():
    N, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    left = 0
    right = a[-1]*b[-1]+1

    while right - left > 1:
        mid = left + (right - left)//2
        if less_than_k(mid, a, b, k):
            right = mid
        else:
            left = mid

    print(right)

if __name__=='__main__':
    main()