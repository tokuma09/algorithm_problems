#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int64_t ans = 0LL;
    for (int X = 2; X <= 2*N; X++) {
        int Y = X - K;
        if (Y >= 2 && Y <= 2*N) {
            int64_t cnt_x, cnt_y;
            if (X <= N+1) cnt_x = X - 1;
            else cnt_x = N - (X - N) + 1;
            if (Y <= N+1) cnt_y = Y - 1;
            else cnt_y = N - (Y - N) + 1;
            ans += cnt_x * cnt_y;
        }
    }
    cout << ans << endl;
}
