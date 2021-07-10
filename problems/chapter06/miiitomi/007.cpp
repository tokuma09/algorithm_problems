// AtCoder ARC101   D - Median of Medians
// https://atcoder.jp/contests/arc101/tasks/arc101_b

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

template <typename T>
struct BIT {
    int n;
    vector<T> data;

    BIT(int n_) {
        n = n_ + 1;
        data.assign(n, 0);
    }

    void add(int x, T a) {
        for (int i = x + 1; i < n; i += (i & -i)) {
            data[i] += a;
        }
    }

    T sum(int x) {
        T s = 0;
        for (int i = x + 1; i > 0; i -= (i & -i)) {
            s += data[i];
        }
        return s;
    }
};

bool f(int x) {
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        if (a[i] >= x) b[i] = 1;
        else b[i] = -1;
    }

    vector<int> s(N+1, 0);
    for (int i = 0; i < N; i++) {
        s[i+1] = s[i] + b[i];
    }

    int min_s = *min_element(s.begin(), s.end());
    for (int i = 0; i <= N; i++) s[i] -= min_s;

    BIT<int> B(*max_element(s.begin(), s.end()) + 1);
    int64_t k = 0;
    for (int i = 0; i <= N; i++) {
        k += B.sum(s[i]);
        B.add(s[i], 1);
    }

    if (k >= ((int64_t)N*(N+1)/2 + 1)/2) return true;
    else return false;
}

int main() {
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int left = *min_element(a.begin(), a.end()) - 1;
    int right = *max_element(a.begin(), a.end()) + 1;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
