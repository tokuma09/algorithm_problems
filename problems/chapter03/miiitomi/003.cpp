#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力
    // 1行目: N
    // 2行目: a_0 a_1 ... a_{N-1}
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a.at(i);
    
    int minimum = INT_MAX;  // intの最大値
    int second = INT_MAX;  // こっちも

    for (int i = 0; i < N; i++) {
        if (a.at(i) < minimum) {
            second = minimum;
            minimum = a.at(i);
        } else if (a.at(i) < second) {
            second = a.at(i);
        }
    }

    cout << second << endl;
}
