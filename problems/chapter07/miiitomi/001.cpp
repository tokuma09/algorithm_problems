#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        while (b[idx] <= a[i]) {
            idx++;
            if (idx == N) break;
        }
        if (idx < N) {
            ans++;
            idx++;
        } else {
            break;
        }
    }

    cout << ans << endl;
}
