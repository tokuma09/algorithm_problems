// AtCoder C - 幅優先探索
// https://atcoder.jp/contests/abc007/tasks/abc007_3

#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C, sy, sx, gy, gx;
    cin >> R >> C >> sy >> sx >> gy >> gx;
    sy--; sx--; gy--; gx--;
    vector<string> v(R);
    for (int i = 0; i < R; i++) cin >> v[i];

    queue<pair<int, int>> Q;
    vector<vector<int>> w(R, vector<int>(C, -1));
    w[sy][sx] = 0;
    Q.push(make_pair(sy, sx));

    while (!Q.empty()) {
        pair<int, int> p = Q.front();
        Q.pop();
        vector<pair<int, int>> q;
        q.push_back(make_pair(p.first, p.second-1));
        q.push_back(make_pair(p.first, p.second+1));
        q.push_back(make_pair(p.first-1, p.second));
        q.push_back(make_pair(p.first+1, p.second));
        for (pair<int, int> x : q) {
            if (v[x.first][x.second] == '#' || w[x.first][x.second] != -1) continue;
            w[x.first][x.second] = w[p.first][p.second] + 1;
            Q.push(x);
        }
    }

    cout << w[gy][gx] << endl;
}
