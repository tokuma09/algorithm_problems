# https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
from bisect import bisect_right

def main():
    N, M = map(int, input().split())
    p = [int(input()) for _ in range(N)]
    
    # append 0 to consider skipping
    p_2 = [i+j for i in p for j in p+[0]] + [0]
    N_2 = N*(N+1)

    p_2.sort()
    output = -float('Inf')
    for i in p_2:
        if i > M:
            continue
        if i == M:
            output = M
            break
        target_score = M - i
        if target_score >= p_2[N_2]:
            index = N_2
        else:
            # binary search to find max key that p[key] =< target_score
            index = bisect_right(p_2, target_score) - 1
        output = max(output, i + p_2[index])

    print(output)

if __name__=='__main__':
    main()