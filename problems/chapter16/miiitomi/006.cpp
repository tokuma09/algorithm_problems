#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

struct Edge {
    int rev, to;
    ll cap;
    Edge(int r, int t, ll c) : rev(r), to(t), cap(c) {}
};

ll rec(vector<vector<Edge>> &G, vector<bool> &seen, int v, ll f) {
    if (seen[v]) return 0LL;
    seen[v] = true;
    if (v == (int)G.size()-1) return f;

    for (auto &e : G[v]) {
        if (e.cap == 0LL) continue;
        ll flow = rec(G, seen, e.to, min(e.cap, f));
        if (flow > 0LL) {
            e.cap -= flow;
            G[e.to][e.rev].cap += flow;
            return flow;
        }
    }
    return 0LL;
}

ll FordFulkerson(vector<vector<Edge>> &G) {
    ll ans = 0LL;
    while (true) {
        vector<bool> seen((int)G.size(), false);
        ll flow = rec(G, seen, 0, INF);
        if (flow == 0) break;
        else ans += flow;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<vector<Edge>> G(N+2);
    ll max_point = 0LL;

    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        if (a <= 0LL) {
            G[0].push_back(Edge((int)G[i].size(), i, -a));
            G[i].push_back(Edge((int)G[0].size()-1, 0, 0LL));
        } else {
            max_point += a;
            G[i].push_back(Edge((int)G[N+1].size(), N+1, a));
            G[N+1].push_back(Edge((int)G[i].size(), i, 0LL));
        }
        for (int j = 2 * i; j <= N; j += i) {
            G[i].push_back(Edge((int)G[j].size(), j, INF));
            G[j].push_back(Edge((int)G[i].size()-1, i, 0LL));
        }
    }

    cout << max_point - FordFulkerson(G) << endl;
}
