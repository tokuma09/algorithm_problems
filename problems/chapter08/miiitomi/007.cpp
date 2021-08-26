#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    bool ans = false;
    // 入力1行目: N K
    // 入力2行目: a_0 a_1 ... a_{N-1}
    // 入力3行目: b_0 b_1 ... b_{N-1}
    int N, K;
    cin >> N >> K;
    unordered_set<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.insert(a);
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        if (A.count(K - b)) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
