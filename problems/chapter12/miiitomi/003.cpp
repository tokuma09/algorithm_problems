#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    priority_queue<int> heap;
    for (int i = 0; i < K; i++) heap.push(a[i]);
    cout << heap.top() << endl;

    for (int i = K; i < N; i++) {
        heap.push(a[i]);
        heap.pop();
        cout << heap.top() << endl;
    }
}
