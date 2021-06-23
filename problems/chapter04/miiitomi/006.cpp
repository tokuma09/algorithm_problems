#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int func(int i, int w, const vector<int> &a) {
    if (w < 0) return 0;

    if (i == 0) {
        if (w == 0) return 1;
        else return 0;
    }
    
    if (memo.at(i).at(w) != -1) return memo.at(i).at(w);

    return memo.at(i).at(w) = (func(i-1, w, a) || func(i-1, w-a[i-1], a));
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    memo.assign(N+1, vector<int>(W+1, -1));    // (N+1)×(W+1) 配列にし, 全て -1 にする.

    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
