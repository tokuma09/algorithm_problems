// atcoder abc045-c
// https://atcoder.jp/contests/abc045/tasks/arc061_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    const int n = S.size();

    int64_t ans = 0;

    for (int bit = 0; bit < (1 << (n-1)); bit++) {
        string S_new = S.substr(0, 1);
        for (int i = 0; i < n-1; i++) {
            if (bit & (1 << i)) {
                ans += stoll(S_new);
                S_new = S.substr(i+1, 1);
            } else {
                S_new.push_back(S.at(i+1));
            }
        }
        ans += stoll(S_new);
    }

    cout << ans << endl;
}
