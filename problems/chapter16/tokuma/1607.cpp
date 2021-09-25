// https://drken1215.hatenablog.com/entry/2019/03/06/102100
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 辺を表す構造体
// rev: 逆辺 (to, from) が G[to] の中で何番目の要素か
// cap: 辺 (from, to) の容量
template <class FLOWTYPE>
struct Edge
{
    int rev, from, to;
    FLOWTYPE cap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c) {}
};

// グラフを表す構造体
template <class FLOWTYPE>
struct Graph
{

    // 隣接リスト
    vector<vector<Edge<FLOWTYPE>>> list;

    // N: 頂点数
    Graph(int N = 0) : list(N) {}

    // グラフの頂点数取得
    size_t size()
    {
        return list.size();
    }

    // Graph インスタンスを G として，
    // G.list[v] を G[v] と書けるようにしておく
    vector<Edge<FLOWTYPE>> &operator[](int i)
    {
        return list[i];
    }

    // 辺 e = (u, v) の逆辺 (v, u) を取得する
    Edge<FLOWTYPE> &redge(const Edge<FLOWTYPE> &e)
    {
        return list[e.to][e.rev];
    }

    // 辺 e = (u, v) に流量 f のフローを流す
    // e = (u, v) の流量が f だけ減少する
    // このとき逆辺 (v, u) の流量を増やす
    void run_flow(Edge<FLOWTYPE> &e, FLOWTYPE f)
    {
        e.cap -= f;
        redge(e).cap += f;
    }

    // 頂点 from から頂点 to へ容量 cap の辺を張る
    // このとき to から from へも容量 0 の辺を張っておく
    void addedge(int from, int to, FLOWTYPE cap)
    {
        int fromrev = (int)list[from].size();
        int torev = (int)list[to].size();
        list[from].push_back(Edge<FLOWTYPE>(torev, from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>(fromrev, to, from, 0));
    }
};

template <class FLOWTYPE>
struct FordFulkerson
{
    static const FLOWTYPE INF = 1 << 30; // 無限大を表す値を適切に
    vector<int> seen;

    FordFulkerson() {}

    // 残余グラフ上で s-t パスを見つける (深さ優先探索)
    // 返り値は s-t パス上の容量の最小値 (見つからなかったら 0)
    // f: s から v へ到達した過程の各辺の容量の最小値
    FLOWTYPE fodfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f)
    {
        // 終端 t に到達したらリターン
        if (v == t)
            return f;

        // 深さ優先探索
        seen[v] = true;
        for (auto &e : G[v])
        {
            if (seen[e.to])
                continue;

            // 容量 0 の辺は実際には存在しない
            if (e.cap == 0)
                continue;

            // s-t パスを探す
            // 見つかったら flow はパス上の最小容量
            // 見つからなかったら f = 0
            long long flow = fodfs(G, e.to, t, min(f, e.cap));

            // s-t パスが見つからなかったら次辺を試す
            if (flow == 0)
                continue;

            // 辺 e に容量 flow のフローを流す
            G.run_flow(e, flow);

            // s-t パスを見つけたらパス上最小容量を返す
            return flow;
        }

        // s-t パスが見つからなかったことを示す
        return 0;
    }

    // グラフ G の s-t 間の最大流量を求める
    // ただしリターン時に G は残余グラフになる
    FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t)
    {
        FLOWTYPE res = 0;

        // 残余グラフに s-t パスがなくなるまで反復
        while (true)
        {
            seen.assign((int)G.size(), 0);
            int flow = fodfs(G, s, t, INF);

            // s-t パスが見つからなかったら終了
            if (flow == 0)
                return res;

            // 答えを加算
            res += flow;
        }

        // no reach
        return 0;
    }
};

int n, m;
inline int conv(int i, int j)
{
    return i * m + j;
}

const int INF = 1 << 29;
int main()
{
    cin >> n >> m;
    vector<string> fi(n);
    for (int i = 0; i < n; ++i)
        cin >> fi[i];
    int num_black = 0;
    int num_adj = 0;
    Graph<int> G(n * m * 3 + 2);
    int s = n * m * 3, t = n * m * 3 + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (fi[i][j] == '.')
                continue;
            ++num_black;

            if (i + 1 < n && fi[i + 1][j] == '#')
            {
                ++num_adj;
                int newv = conv(i, j) + n * m;
                G.addedge(newv, t, 1);
                G.addedge(conv(i, j), newv, INF);
                G.addedge(conv(i + 1, j), newv, INF);
            }

            if (j + 1 < m && fi[i][j + 1] == '#')
            {
                ++num_adj;
                int newv = conv(i, j) + n * m * 2;
                G.addedge(s, newv, 1);
                G.addedge(newv, conv(i, j), INF);
                G.addedge(newv, conv(i, j + 1), INF);
            }
        }
    }
    FordFulkerson<int> ff;
    int flow = ff.solve(G, s, t);

    cout << num_black - (num_adj - flow) << endl;
}
