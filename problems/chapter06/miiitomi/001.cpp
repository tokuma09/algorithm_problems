#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(b.begin(), b.end(), a[i]);
        cout << distance(b.begin(), iter) << " ";
    }
    cout << endl;
}
