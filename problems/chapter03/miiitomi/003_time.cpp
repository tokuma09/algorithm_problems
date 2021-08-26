#include <bits/stdc++.h>
using namespace std;

int func_003(int N, vector<int> &a) {
    // 003.cppのmain関数, 入出力以外.
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

    return second;
}

int main() {
    for (int i = 0; i < 9; i++) {
        int N = pow(10, i);  // N = 10**i とする
        vector<int> a(N);
        for (int i = 0; i < N; i++) a.at(i) = rand();  // INT_MAX以下の非負整数からなるベクトルを適当に生成

        auto start = chrono::system_clock::now();  // 時間計測初め

        int ans = func_003(N, a);  // 003.cpp の main関数（入出力以外）を実行

        auto end = chrono::system_clock::now();  // 時間計測終わり
        double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
        cout << "N = 10**" << i << ": " << elapsed << " ms" << endl;  // 実行時間の出力
    }
}
