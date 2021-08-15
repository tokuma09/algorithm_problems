import heapq

def main():
    K, N = map(int, input().split())
    a = list(map(lambda x: -int(x), input().split()))
    # make heap to keep eyes on max
    S = a[0:K].copy()
    heapq.heapify(S)

    output = [-S[0]]
    for i in a[K+1:N]:
        if i > output[-1]:
            output.append(-S[0])
        else:
            heapq.heappushpop(S, i)
            output.append(-S[0])

    print(' '.join(map(str, output)))

if __name__=='__main__':
    main()