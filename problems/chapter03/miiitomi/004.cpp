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

    int minimum = INT_MAX;  // intの最大値.
    int maximum = INT_MIN;  // intの最小値.

    for (int i = 0; i < N; i++) {
        if (a.at(i) < minimum) minimum = a.at(i);
        if (a.at(i) > maximum) maximum = a.at(i);
    }

    cout << maximum - minimum << endl;
}
