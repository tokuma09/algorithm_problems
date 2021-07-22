#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
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
    vector<int> b(N);
    for (int i = 0; i < N; i++) cin >> b[i];

    for (int i = 0; i < N; i++) {
        if (A.count(K - b[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
