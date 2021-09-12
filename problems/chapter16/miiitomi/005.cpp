// https://atcoder.jp/contests/soundhound2018/tasks/soundhound2018_c
#include <bits/stdc++.h>
using namespace std;

vector<int> vi = {1, -1, 0, 0};
vector<int> vj = {0, 0, 1, -1};

struct Edge {
    int rev, to, cap;
    Edge(int r_, int t_, int c_) : rev(r_), to(t_), cap(c_) {}
};

bool rec(vector<vector<Edge>> &G, vector<bool> &seen, int v) {
    int N = (int)G.size();
    seen[v] = true;
    if (v == N - 1) return true;

    for (auto &e : G[v]) {
        if (seen[e.to] || e.cap == 0) continue;

        if (rec(G, seen, e.to)) {
            e.cap--;
            if (v != 0 && e.to != N-1) G[e.to][e.rev].cap++;
            return true;
        }
    }
    return false;
}

int FordFulkerson(vector<vector<Edge>> &G) {
    int N = (int)G.size();
    int ans = 0;
    vector<bool> seen(N, false);
    while (true) {
        seen.assign(N, false);
        if (rec(G, seen, 0)) ans++;
        else break;
    }
    return ans;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<pair<int, int>> Nodes;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.') Nodes.push_back(make_pair(i, j));
        }
    }

    int N = (int)Nodes.size() + 2;
    vector<vector<Edge>> G(N);

    for (int i = 0; i < (int)Nodes.size(); i++) {
        pair<int, int> v = Nodes[i];
        if ((v.first + v.second) % 2 == 0) {
            G[0].push_back(Edge(0, i+1, 1));
            for (int k = 0; k < 4; k++) {
                pair<int, int> nv = make_pair(v.first + vi[k], v.second + vj[k]);
                auto iter = lower_bound(Nodes.begin(), Nodes.end(), nv);
                if (iter->first != nv.first || iter->second != nv.second) continue;
                int j = (int)distance(Nodes.begin(), iter);
                G[i+1].push_back(Edge((int)G[j+1].size(), j+1, 1));
                G[j+1].push_back(Edge((int)G[i+1].size()-1, i+1, 0));
            }
        } else {
            G[i+1].push_back(Edge((int)G[N-1].size(), N-1, 1));
        }
    }

    cout << N - 2 - FordFulkerson(G) << endl;
}
