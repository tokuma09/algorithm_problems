// AtCoder ABC131   D - Megalomania
// https://atcoder.jp/contests/abc131/tasks/abc131_d

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) return (a.second < b.second);
    else return (a.first <= b.first);
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> W(N);
    for (int i = 0; i < N; i++) cin >> W[i].first >> W[i].second;
    sort(W.begin(), W.end(), cmp);

    int now = 0;
    for (int i = 0; i < N; i++) {
        if (now + W[i].first > W[i].second) {
            cout << "No" << endl;
            return 0;
        } else {
            now += W[i].first;
        }
    }
    cout << "Yes" << endl;
}
