import bisect
import time

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
    print('main output')
    time_a = time.time()
    main(a)
    time_b = time.time()
    print('main time', time_b - time_a)
    time.sleep(2)
    print()
    print('bisect.bisect_left output')
    time_a = time.time()
    bi_left(a)
    time_b = time.time()
    print('isect.bisect_left time', time_b - time_a)
    time.sleep(2)
    print()
    print('bisect.bisect_right output')
    time_a = time.time()
    bi_right(a)
    time_b = time.time()
    print('isect.bisect_left time', time_b - time_a)
    time.sleep(2)
    print()
    print('1 line dict output')
    time_a = time.time()
    print({e: i for i, e in enumerate(sorted(set(a)))})
    time_b = time.time()
    print('1 line dict output', time_b - time_a)