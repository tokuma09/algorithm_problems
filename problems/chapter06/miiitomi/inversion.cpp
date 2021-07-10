// AtCoder Chokudai SpeedRun 001    J - 転倒数
// https://atcoder.jp/contests/chokudai_s001/tasks/chokudai_S001_j

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    BIT<int> B(*max_element(a.begin(), a.end()) + 1);
    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - B.sum(a[i]);
        B.add(a[i], 1);
    }

    cout << ans << endl;
}
