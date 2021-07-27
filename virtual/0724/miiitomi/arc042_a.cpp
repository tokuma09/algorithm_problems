#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &x, pair<int, int> &y) {
    if (x.second != y.second) return (x.second > y.second);
    else return (x.first < y.first);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) {
        v[i].first = i + 1;
        v[i].second = -1;
    }
    for (int m = 0; m < M; m++) {
        int a;
        cin >> a;
        a--;
        v[a].second = m;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) {
        cout << v[i].first << endl;
    }
}
