from bisect import bisect_right
def main():
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()

    res = []
    for i in range(N):
        j = bisect_right(b, a[i])
        res.append(j)
    
    ans = len(set(res))
    if N in res:
        ans -= 1
    print(ans)
if __name__=='__main__':
    main()