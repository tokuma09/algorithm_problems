// 第７回日本情報オリンピック 本選  C - ダーツ
// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    int K = ((N * (N + 1)) / 2) + N;
    vector<int> Q(K);
    int counter = 0;
    for (int i = 0; i < N; i++) {
        Q[counter] = P[i];
        counter++;
        for (int j = i; j < N; j++) {
            Q[counter] = P[i] + P[j];
            counter++;
        }
    }

    sort(Q.begin(), Q.end());

    int ans = 0;
    for (int i = 0; i < K; i++) {
        if (Q[i] > M) {
            break;
        }
        auto iter = lower_bound(Q.begin(), Q.end(), M - Q[i] + 1);
        if (iter == Q.begin()) {
            ans = max(ans, Q[i]);
        } else {
            iter--;
            ans = max(ans, Q[i] + *iter);
        }
    }

    cout << ans << endl;
}
