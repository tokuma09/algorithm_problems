// AtCoder ARC092   C - 2D Plane 2N Points
// https://atcoder.jp/contests/arc092/tasks/arc092_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> r(N), b(N);
    for (int i = 0; i < N; i++) cin >> r[i].first >> r[i].second;
    for (int i = 0; i < N; i++) cin >> b[i].first >> b[i].second;

    sort(b.begin(), b.end());
    vector<bool> red_matched(N, false);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = -1;
        int y_max = -1;
        for (int j = 0; j < N; j++) {
            if (!red_matched[j] && r[j].first < b[i].first && r[j].second < b[i].second && r[j].second > y_max) {
                idx = j;
                y_max = r[j].second;
            }
        }
        if (idx != -1) {
            red_matched[idx] = true;
            ans++;
        }
    }

    cout << ans << endl;
}
