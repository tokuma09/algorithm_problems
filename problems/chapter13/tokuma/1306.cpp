// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891
// https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-%E3%82%B0%E3%83%A9%E3%83%95%E4%B8%8A%E3%81%AE%E6%A7%98%E3%80%85%E3%81%AA%E4%BE%8B%E9%A1%8C
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

// 探索
vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1;    // サイクル中に含まれる頂点 pos
stack<int> hist; // 訪問履歴

void dfs(const Graph &G, int v)
{
    seen[v] = true;
    // 帰りがけで到達したらこのhistからデータが抜ける
    hist.push(v);
    for (auto nv : G[v])
    {

        // 帰りがけで到達していればスルー
        if (finished[nv])
        {
            continue;
        }

        // nvはサイクルの中の頂点
        if (seen[nv] && !finished[nv])
        {

            pos = nv;
            return;
        }

        // 再帰的に探索
        // サイクルの中の頂点でなければ、深さ優先で行う
        dfs(G, nv);

        // サイクル検出したならば真っ直ぐに抜けていく
        if (pos != -1)
        {
            return;
        }
    }
    hist.pop();
    finished[v] = true;
}

int main()
{
    // 頂点数 (サイクルを一つ含むグラフなので辺数は N で確定)
    int N, M;
    cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false), finished.assign(N, false);

    // 深さ優先探索
    for (int v = 0; v < N; ++v)
    {
        if (seen[v])
        {
            continue;
        }
        dfs(G, v);
    }

    // 帰りがけですべて行っていればなし
    if (hist.empty())
    {
        cout << "No cycle" << endl;
    }
    else
    {
        // サイクルを復元
        vector<int> cycle;
        while (!hist.empty())
        {
            int t = hist.top();
            cycle.push_back(t);
            hist.pop();

            // 最後にチェックしたものと同じであれば、そこまででサイクル完成
            if (t == pos)
            {
                break;
            }
        }

        // 答えをひっくり返す
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Found!" << endl;
        for (auto v : cycle)
        {
            cout << v << endl;
        }
    }
}
