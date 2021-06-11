// atcoder abc051-b
// https://atcoder.jp/contests/abc051/tasks/abc051_b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, S;
    cin >> K >> S;

    int ans = 0;

    for (int X = 0; X <= K; X++) {
        for (int Y = 0; Y <= K; Y++) {
            int Z = S - X - Y;
            if (Z >= 0 && Z <= K) ans++;
        }
    }

    cout << ans << endl;
}
