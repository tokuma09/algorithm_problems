// give up
// https://drken1215.hatenablog.com/entry/2018/03/09/003000

#include <iostream>
#include <vector>
using namespace std;

inline long long mod(long long a, long long m)
{
    return (a % m + m) % m;
}

inline long long mul(long long a, long long b, long long m)
{
    a = mod(a, m);
    b = mod(b, m);
    if (b == 0)
        return 0;
    long long res = mul(mod(a + a, m), b >> 1, m);
    if (b & 1)
        res = mod(res + a, m);
    return res;
}

long long pow(long long a, long long n, long long m)
{
    if (n == 0)
        return 1 % m;
    long long t = pow(a, n / 2, m);
    t = mul(t, t, m);
    if (n & 1)
        t = mul(t, a, m);
    return t;
}

vector<pair<long long, long long>> prime_factor(long long n)
{
    vector<pair<long long, long long>> res;
    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int exp = 0;
            while (n % i == 0)
            {
                ++exp;
                n /= i;
            }
            res.push_back(make_pair(i, exp));
        }
    }
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}
long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
long long LCM(long long a, long long b)
{
    long long g = GCD(a, b);
    return a / g * b;
}

const long long L = 50;
long long solve(long long A, long long M)
{
    if (A == 0)
        return M;
    if (A == 1)
        return 1;
    if (M == 1)
        return L;
    long long phiM = M;
    vector<pair<long long, long long>> divM = prime_factor(M);
    for (int i = 0; i < divM.size(); ++i)
    {
        long long p = divM[i].first;
        phiM *= p - 1;
        phiM /= p;
    }
    long long y = solve(A, phiM);
    long long lcm = LCM(phiM, M);
    long long res = pow(A, y, lcm);
    while (res < L)
        res += lcm;
    return res;
}
int main()
{
    int Q;
    while (cin >> Q)
    {
        for (int i = 0; i < Q; ++i)
        {
            long long a, m;
            cin >> a >> m;
            long long res = solve(a, m);
            cout << res << endl;
        }
    }
}
