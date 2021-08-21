#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(b.begin(), b.end(), a[i]);
        cout << distance(b.begin(), iter) + 1;
        if (i < N-1) cout << " ";
        else cout << endl;
    }
}
