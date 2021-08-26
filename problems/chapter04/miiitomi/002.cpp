#include <iostream>
#include <vector>
using namespace std;

vector<int64_t> memo;

int64_t tribo(int n) {
    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }

    if (memo[n] != -1LL) return memo[n];

    return memo[n] = tribo(n-1) + tribo(n-2) + tribo(n-3);
}

int main() {
    int N;
    cin >> N;
    memo.assign(N+1, -1LL);

    cout << tribo(N) << endl;
}
