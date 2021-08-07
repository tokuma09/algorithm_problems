# https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_f
# https://tomorinao.blogspot.com/2018/09/f-modularpowerequation.html
'''
Assume A >= 2
Euler theorem: A^phi(N) = 1(mod N), where A and N are coprime
When x is large, A^(x + phi(M)) = A^x(mod M)
return A^x % LCM(phi(M), M)
'''
from math import gcd, sqrt, ceil

def phi(n):
    # Eular phi function
    phi = n
    prime_max = n
    p = 2
    while p*p <= prime_max:
        if n % p == 0:
            phi = phi*(p - 1)//p
            while n % p == 0:
                n //= p
        p += 1
    if n > 1:
        phi = phi*(n-1)//n # why..
    return phi

def lcm(a, b):
    # return int of lcm
    return a * b // gcd(a, b)

def MPE(A, M):
    L =30
    if A == 0: return M
    if A == 1: return 1
    if M == 1: return L
    phiM = phi(M)
    x = MPE(A, phiM)
    l = lcm(phiM, M)
    output = pow(A, x, l)
    while output < L:
        output += l
    return output

def main():
    Q = int(input())
    for _ in range(Q):
        A, M = map(int, input().split())
        output = MPE(A, M)
        print(output)

if __name__=='__main__':
    main()