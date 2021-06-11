// atcoder abc081-b
// https://atcoder.jp/contests/abc081/tasks/abc081_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    bool done = false;
    int ans = -1;
    while (not done) {
        ans++;
        for (int i = 0; i < N; i++) {
            if (A.at(i) % 2 == 0) {
                A.at(i) /= 2;
            } else {
                done = true;
                break;
            }
        }
    }

    cout << ans << endl;
}
