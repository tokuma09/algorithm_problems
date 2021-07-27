#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin >> S;
    int cnt = 0;
    for (int i = A; i <= C; i++) {
        if (S[i] == '#') cnt++;
        else cnt = 0;
        if (cnt == 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cnt = 0;
    for (int i = B; i <= D; i++) {
        if (S[i] == '#') cnt++;
        else cnt = 0;
        if (cnt == 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (C < D) {
        cout << "Yes" << endl;
        return 0;
    }

    cnt = 0;
    for (int i = B-1; i<= D+1; i++) {
        if (S[i] == '.') cnt++;
        else cnt = 0;
        if (cnt == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
