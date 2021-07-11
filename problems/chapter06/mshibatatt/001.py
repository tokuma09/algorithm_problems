import bisect

def main(a):
    # a = list(map(int, input().split()))
    N = len(a)
    sorted_a = sorted(a)
    output = []
    for i in a:
        left, right = 0, N-1 
        if sorted_a[left] == i:
            output.append(left)
        else:
            while right - left > 1:
                mid = left + (right - left)//2
                if sorted_a[mid] >= i:
                    right = mid
                else:
                    left = mid 
            output.append(right)
    print(output)

def bi_left(a):
    # a = list(map(int, input().split()))
    sorted_a = sorted(a)

    output = []
    for i in a:
        output.append(bisect.bisect_left(sorted_a, i))
    
    print(output)

def bi_right(a):
    # a = list(map(int, input().split()))
    sorted_a = sorted(a)

    output = []
    for i in a:
        output.append(bisect.bisect_right(sorted_a, i))
    
    print(output)



if __name__=='__main__':
    a = list(map(int, input().split()))
    print('a:', a)
    print('main')
    main(a)
    print('bisect.bisect_left')
    bi_left(a)
    print('bisect.bisect_right')
    bi_right(a)
    print('1 line dict')
    print({e: i for i, e in enumerate(sorted(set(a)))})