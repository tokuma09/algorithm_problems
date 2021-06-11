#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力は以下の形で与えられるものとする.
    // 1行目: N v
    // 2行目: a_0 a_1 ... a_{N-1}
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (a.at(i) == v) ans++;
    }

    cout << ans << endl;
}
