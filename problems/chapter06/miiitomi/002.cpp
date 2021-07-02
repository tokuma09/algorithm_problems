// atcoder ABC077   C - Snuke Festival
// https://atcoder.jp/contests/abc077/tasks/arc084_a

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    int64_t ans = 0LL;
    for (int i = 0; i < N; i++) {
        auto iter1 = lower_bound(A.begin(), A.end(), B[i]);
        auto iter2 = lower_bound(C.begin(), C.end(), B[i]+1);
        ans += (int64_t)distance(A.begin(), iter1) * (N - distance(C.begin(), iter2));
    }

    cout << ans << endl;
}
