#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int ans = 0;
    // 入力1行目: N M
    // 入力2行目: a_0 a_1 ... a_{N-1}
    // 入力3行目: b_0 b_1 ... b_{M-1}
    unordered_set<int> U;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        U.insert(a);
    }
    for (int i = 0; i < M; i++) {
        int b;
        cin >> b;
        if (U.count(b)) ans++;
    }

    cout << ans << endl;
}
