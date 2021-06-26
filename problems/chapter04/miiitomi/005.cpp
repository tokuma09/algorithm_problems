#include <iostream>
using namespace std;

int K;
int ans = 0;

void func(string S) {
    if (stoll('0'+S) > K) {
        return;
    }

    bool three = false;
    bool five = false;
    bool seven = false;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '3') three = true;
        else if (S.at(i) == '5') five = true;
        else seven = true;
    }

    if (three && five && seven) ans++;

    func(S + '3');
    func(S + '5');
    func(S + '7');
}

int main() {
    cin >> K;
    func("");
    cout << ans << endl;
}
