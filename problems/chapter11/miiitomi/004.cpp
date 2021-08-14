// AtCoder ARC090   D - People on a Line
// https://atcoder.jp/contests/arc090/tasks/arc090_b

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>> &G, vector<bool> &reached, vector<int> &x, bool &b, int i) {
    reached[i] = true;
    for (pair<int, int> p : G[i]) {
        if (reached[p.first]) {
            if (x[i] + p.second != x[p.first]) {
                b = true;
                return;
            }
        } else {
            x[p.first] = x[i] + p.second;
            dfs(G, reached, x, b, p.first);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N, vector<pair<int, int>>(0));

    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        G[l].push_back(make_pair(r, d));
        G[r].push_back(make_pair(l, -d));
    }

    vector<bool> reached(N, false);
    vector<int> x(N);
    bool b = false;

    for (int i = 0; i < N; i++) {
        if (reached[i]) continue;
        x[i] = 0;
        dfs(G, reached, x, b, i);
    }

    if (b) cout << "No" << endl;
    else cout << "Yes" << endl;
}
