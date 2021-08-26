# https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%A4%AE%E5%80%A4%E3%81%AE%E4%B8%AD%E5%A4%AE%E5%80%A4
# https://www.slideshare.net/matuura/bfprt-algorithm-13249564

def pivot(a, start, end):
    # return value of median of medians
    medians = []
    for i in range(start, end, 5):
        j = min(i + 5, end)
        med = median5(a[i:j])
        medians.append(med)
    if len(medians) == 1:
        return medians[0]

    start = 0
    end = len(medians)
    k = end//2    
    return kth_smallest(medians, k+1, start, end)

def median5(a):
    a.sort()
    # return median value
    k = len(a)//2
    return a[k]

def partition(a, start, end, pivot_index = None, pivot_value = None):
    # make array parted left <= pivot < right
    # return index of pivot 
    if pivot_index != None:
        pivot_value = a[pivot_index]
        a[pivot_index], a[-1] = a[-1], a[pivot_index]
    else:
        temp_max = -float('Inf')
        temp_max_id = start
    if pivot_index == None and pivot_value == None:
        raise AssertionError('Neither pivot_index and pivot_value should be None')
    
    # i is index where less than pivot_values are stored
    i = start
    for j in range(start, end):
        if a[j] <= pivot_value:
            a[i], a[j] = a[j], a[i]
            # max value in left to be last
            if pivot_index == None:
                if a[i] > temp_max:
                    temp_max = max(a[i], temp_max)
                    temp_max_id = i
            i += 1
        
    # a[i] should be pivot_value
    if pivot_index != None:
        a[i], a[-1] = a[-1], a[i] 
    else:
        # make i is right end of left
        i -= 1
        a[temp_max_id], a[i] = a[i], a[temp_max_id]

    return i

def kth_smallest(a, k, start, end):
    pivot_index = None
    while pivot_index != k-1:
        pivot_v = pivot(a, start, end)
        pivot_index = partition(a, start, end, pivot_value = pivot_v)
        if pivot_index < k-1:
            start = pivot_index + 1
        elif pivot_index > k-1:
            end = pivot_index
    return a[k-1]

def main():
    import random
    from time import time
    
    for i in range(1, 6):
        N = 10**i
        a = list(range(N))
        k = random.choice(a)+1
        random.shuffle(a)

        start = time()
        output = kth_smallest(a, k, 0, len(a))
        end = time()

        print('N:', N, ', k:', k, ', return:', output, ', time:', end-start)

if __name__=='__main__':
    main()