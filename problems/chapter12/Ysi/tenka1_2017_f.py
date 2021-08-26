import math
def prime_division(n):
    x = 2
    d = {}
    while x * x <= n:
        while n % x == 0:
            n //= x
            d[x] = d.get(x, 0) + 1
        x += 1
    if n > 1:
        d[n] = d.get(n, 0) + 1
    return d
 
def phi(n):
    for p in prime_division(n):
        n = (n*(p-1))//p
    return n
 

def lcm(x, y):
    return x*y // math.gcd(x, y)

def solve(A, M):
    if pow(A, M, M) == 0:
        return M
    if 1 in {A, M}:
        return 1

    phiM = phi(M)

    return pow(A, solve(A, phiM), lcm(phiM, M))
    

def main():
    Q = int(input())
    for _ in range(Q):
        a, m = map(int, input().split())
        print(solve(a, m))

if __name__=='__main__':
    main()