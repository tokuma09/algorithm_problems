def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    a_sorted = sorted(a)
    b_sorted = sorted(b)
    c_sorted = sorted(c)

    ans = 0
    for b in b_sorted:
        # aから何個利用できるか
        if a_sorted[0] >= b:
            ok_a = 0
        elif a_sorted[-1] < b:
            ok_a = n
        else:
            ok_a = -1
            ng_a = n
            while abs(ok_a - ng_a) > 1:
                mid = (ok_a + ng_a) // 2
                if a_sorted[mid] < b:
                    ok_a = mid
                else:
                    ng_a = mid

            ok_a += 1

        # cから何個利用できるか
        if b >= c_sorted[-1]:
            ng_c = n
        elif b < c_sorted[0]:
            ng_c = 0
        else:
            ok_c = n
            ng_c = -1
            while abs(ok_c - ng_c) > 1:
                mid = (ok_c + ng_c) // 2
                if b < c_sorted[mid]:
                    ok_c = mid
                else:
                    ng_c = mid
            ng_c += 1
        ans += ok_a * (n - ng_c)

    print(ans)
if __name__=='__main__':
    main()