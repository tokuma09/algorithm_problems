// give up
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
T median(std::vector<T>& c)
{
    size_t n = c.size() / 2;
    std::nth_element(c.begin(), c.begin() + n, c.end());
    return c[n];
}

int rec(vector<int> a, int k)
{
    // 終端条件
    if (a.size() <= 100)
    {
        sort(a.begin(), a.end());
        return a[k];
    }

    // a の要素を 5 個ずつ切り出して、各グループのメディアンを集める
    vector<int> a2;
    for (int i = 0; i < a.size(); i += 5)
    {
        vector<int> sub_vec= {&a[i], &a[i+5]};
        a2.push_back(median(sub_vec));
    }

    // a2 のメディアンを求める
    int m = rec(a2, a.size() / 10);

    // a を 3 つのグループに分ける
    vector<int> p, q, r;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] < m)
            p.push_back(a[i]);
        else if (a[i] == m)
            q.push_back(a[i]);
        else
            r.push_back(a[i]);
    }

    // 再帰的に解く
    int res;
    if (k <= p.size())
        return rec(p, k);
    else if (k <= p.size() + q.size())
        return m;
    else
        return rec(r, k - p.size() - q.size());
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    cout << rec(a, K-1) << endl;
}
