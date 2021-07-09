// AtCoder ABC026   D - 高橋君ボール1号
// https://atcoder.jp/contests/abc026/tasks/abc026_d

#include <bits/stdc++.h>
using namespace std;

int A, B, C;

double f(double t) {
    return (A * t) + B * sin(C * t * M_PI);
}

int main() {
    cin >> A >> B >> C;
    double left = (100.0 - B) / A;
    double right = (100.0 + B) / A;
    double mid = (left + right) / 2;

    while (abs(f(mid) - 100.0) >= 1e-7) {
        if (f(mid) > 100.0) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right) / 2;
    }

    cout << fixed << setprecision(10) << mid << endl;
}
