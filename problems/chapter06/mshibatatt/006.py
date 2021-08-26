# https://atcoder.jp/contests/abc026/tasks/abc026_d

from math import sin, pi

def main():
    a, b, c = map(int, input().split())

    left = 0
    right = (100+b)/a + 1
    t = left + (right - left)/2
    ft = a*t + b*sin(c*t*pi) - 100
    while abs(ft) > 10**(-6):
        if ft > 0:
            right = t
        else:
            left = t
        t = left + (right - left)/2
        ft = a*t + b*sin(c*t*pi) - 100
        
    print(t)

if __name__=='__main__':
    main()