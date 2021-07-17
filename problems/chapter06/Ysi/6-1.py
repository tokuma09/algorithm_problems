def main():
    n = int(input())
    a = list(map(int, input().split()))

    a_sorted = sorted(a)

    ans = [0] * n
    # 各要素について, 二分探索によって何番目に位置しているかを確認. 
    for i in range(n):
        ok = n
        ng = -1
        # 二分探索
        while abs(ok - ng) > 1: 
            mid = (ok + ng) // 2
            if a[i] <= a_sorted[mid]:
                ok = mid
            else:
                ng = mid
        ans[i] = ok

    print(ans)
if __name__=='__main__':
    main()