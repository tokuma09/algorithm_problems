#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    // 入力
    // 1行目: N（入力される数字・演算子の数）
    // 2行目: a_1 a_2 ... a_N
    stack<int> S;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        if (a == "+") {
            int x = S.top();
            S.pop();
            int y = S.top();
            S.pop();
            S.push(x + y);
        } else if (a == "-") {
            int x = S.top();
            S.pop();
            int y = S.top();
            S.pop();
            S.push(y - x);
        } else if (a == "*") {
            int x = S.top();
            S.pop();
            int y = S.top();
            S.pop();
            S.push(x * y);
        } else {
            int x = stoi(a);
            S.push(x);
        }
    }

    cout << S.top() << endl;
}
