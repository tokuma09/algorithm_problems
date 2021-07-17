from math import sin, pi
def main():
    a, b, c = map(int, input().split())

    def val(t):
        return a * t + b * sin(c * t * pi)

    def is_ok(mid):
        v = val(mid)
        return v > 100
    
    def bisect(ng, ok, error):
        while (error > 10 ** -6):
            mid = (ok + ng) / 2
            if is_ok(mid):
                ok = mid
            else:
                ng = mid
            error = abs(val(ok) - 100)
        return ok

    ans = bisect(0, 100, 100)
    print(ans)
if __name__=='__main__':
    main()