// https://qiita.com/drken/items/996d80bcae64649a6580#3-4-%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a);
        deg[a]++;
    }

    vector<int> order;
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        if (deg[i] == 0) {
            Q.push(i);
            order.push_back(i);
        }
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (int nv : G[v]) {
            deg[nv]--;
            if (deg[nv] == 0) {
                order.push_back(nv);
                Q.push(nv);
            }
        }
    }

    reverse(order.begin(), order.end());
    for (int i = 0; i < N; i++) cout << order[i] << endl;
}
