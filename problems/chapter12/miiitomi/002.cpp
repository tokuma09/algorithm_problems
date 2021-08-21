// AtCoder ABC121   C - Energy Drink Collector
// https://atcoder.jp/contests/abc121/tasks/abc121_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        V[i] = make_pair(a, b);
    }
    sort(V.begin(), V.end());
    int64_t ans = 0LL;
    for (int i = 0; i < N; i++) {
        if (M > V[i].second) {
            M -= V[i].second;
            ans += (int64_t)V[i].first * V[i].second;
        } else {
            ans += (int64_t)V[i].first * M;
            break;
        }
    }
    cout << ans << endl;
}
