// https://drken1215.hatenablog.com/entry/2018/09/08/011500?_ga=2.135966193.1107495987.1625194483-791597362.1625194483

#include <iostream>
#include <vector>
using namespace std;

// 情報構造
template <class Abel>
struct BIT
{
    const Abel UNITY_SUM = 0; // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) {}
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add(int a, Abel x)
    {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a)
    {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b)
    {
        return sum(b - 1) - sum(a - 1);
    }

    /* debug */
    void print()
    {
        for (int i = 1; i < (int)dat.size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

int main()
{
    long long N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    int low = 0, high = 1 << 30;
    const int geta = N + 1;
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        long long num = 0;
        BIT<long long> bit(N * 2 + 10);
        int sum = 0;
        bit.add(sum + geta, 1);
        for (int i = 0; i < N; ++i)
        {
            int val;
            if (a[i] <= mid)
                val = 1;
            else
                val = -1;
            sum += val;
            num += bit.sum(1, sum + geta);
            bit.add(sum + geta, 1);
        }
        if (num > (N + 1) * N / 2 / 2)
            high = mid;
        else
            low = mid;
    }
    cout << high << endl;
}
