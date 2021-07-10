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

    BIT<int> B(N);
    for (int i = 0; i < N; i++) {
        B.add(i, a[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << B.sum(i) << endl;
    }
}
