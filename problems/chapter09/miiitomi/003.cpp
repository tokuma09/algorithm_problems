#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    stack<int> st;
    vector<pair<int, int>> v(N);
    int next = 0;

    for (int i = 0; i < 2*N; i++) {
        if (S[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                cout << "No" << endl;
                return 0;
            }
            int x = st.top();
            st.pop();
            pair<int, int> p = make_pair(x, i);
            v[next] = p;
            next++;
        }
    }

    if (not st.empty()) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << v[i].first << " - " << v[i].second << endl;
    }
}
