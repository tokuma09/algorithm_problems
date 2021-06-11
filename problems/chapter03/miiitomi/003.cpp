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

    // 2番目に小さい3値を求める.
    // 1番小さい値が2つ以上ある場合は, 1位タイを出力する.
    int minimum = pow(10, 9);  // 十分大きな値とする.
    int second = pow(10, 9) + 1;  // こっちも.
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
