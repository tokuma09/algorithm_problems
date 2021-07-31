#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int ans = 0;
    // 入力1行目: N M
    // 入力2行目: a_0 a_1 ... a_{N-1}
    // 入力3行目: b_0 b_1 ... b_{M-1}
    int N, M;
    cin >> N >> M;
    unordered_map<int, int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (A.count(a)) {
            A[a] += 1;
        } else {
            A[a] = 1;
        }
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        if (A.count(b)) {
            ans += A[b];
        }
    }
    cout << ans << endl;
}
