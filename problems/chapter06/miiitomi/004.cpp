// POJ #2456 Aggressive cows
// http://poj.org/problem?id=2456

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> x;

bool f(int m) {
    int last = 0;
    int counter = 1;
    for (int i = 1; i < N; i++) {
        if (x[i] - x[last] >= m) {
            last = i;
            counter += 1;
        }
        if (counter == C) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> C;
    x.resize(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    
    sort(x.begin(), x.end());

    int left = 1;
    int right = x[N-1] + 1;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;
}
