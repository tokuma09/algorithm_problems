// AtCoder ARC037   C - 億マス計算
// https://atcoder.jp/contests/arc037/tasks/arc037_c

#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> a, b;

bool f(int64_t m) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
        int64_t x = (m / a[i]) + 1;
        auto iter = lower_bound(b.begin(), b.end(), x);
        counter += distance(b.begin(), iter);
        if (counter >= K) return true;
    }
    return false;
}

int main() {
    cin >> N >> K;
    a.resize(N);
    b.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int64_t left = 0;
    int64_t right = (int64_t)a[N-1] * b[N-1];
    int64_t mid;

    while (right - left > 1) {
        mid = (left + right) / 2;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}
