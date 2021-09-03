// AtCoder ABC061   D - Score Attack
// https://atcoder.jp/contests/abc061/tasks/abc061_d

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
    }
    vector<ll> score(N, -INF);
    score[0] = 0;

    for (int iter = 1; iter <= N; iter++) {
        bool update = true;
        bool last_vertex_update = false;

        for (int v = 0; v < N; v++) {
            if (score[v] == -INF) continue;

            for (auto p : G[v]) {
                if (score[p.first] < score[v] + p.second) {
                    score[p.first] = score[v] + p.second;
                    update = true;
                    if (p.first == N-1) last_vertex_update = true;
                }
            }
        }

        if (!update) break;

        if (iter == N && last_vertex_update) {
            cout << "inf" << endl;
            return 0;
        }
    }

    cout << score[N-1] << endl;
}
