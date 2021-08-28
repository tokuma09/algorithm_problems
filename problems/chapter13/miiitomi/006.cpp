// https://qiita.com/drken/items/996d80bcae64649a6580#3-5-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A&lang=jp

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> seen;
vector<bool> finished;
stack<int> S;
int pos = -1;

void dfs(const vector<vector<int>> &G, int v) {
    seen[v] = true;
    S.push(v);

    for (int nv : G[v]) {
        if (finished[nv]) continue;

        if (seen[nv]) {
            pos = nv;
            return;
        }

        dfs(G, nv);
        if (pos != -1) return;
    }
    S.pop();
    finished[v] = true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(N, false);
    finished.assign(N, false);

    for (int i = 0; i < N; i++) {
        if (!finished[i]) dfs(G, i);
        if (pos != -1) break;
    }

    if (pos == -1) cout << "No" << endl;
    else {
        vector<int> cycle;
        while (S.top() != pos) {
            cycle.push_back(S.top());
            S.pop();
        }
        cycle.push_back(pos);
        for (int i = (int)cycle.size() - 1; i >= 0; i--) cout << cycle[i] << " ";
        cout << endl;
    }
}
