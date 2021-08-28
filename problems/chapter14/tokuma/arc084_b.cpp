// https://drken1215.hatenablog.com/entry/2021/07/30/160000

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 無限大を表す値
const int INF = 1 << 29;

int main()
{
    // 入力
    int K;
    cin >> K;

    // 距離配列と deque
    vector<int> dist(K, INF);
    deque<int> que;

    // 初期値として 1 を挿入
    dist[1] = 1;
    que.push_front(1);

    // 0-1 BFS
    while (!que.empty())
    {
        // deque の先頭要素を取り出す
        int v = que.front();
        que.pop_front();

        // 「×10」を試す
        // コスト 0 なので deque の先頭に push
        int v2 = (v * 10) % K;
        if (dist[v2] > dist[v])
        {
            dist[v2] = dist[v];
            que.push_front(v2);
        }

        // 「+1」を試す
        // コスト 1 なので deque の末尾に push
        v2 = (v + 1) % K;
        if (dist[v2] > dist[v] + 1)
        {
            dist[v2] = dist[v] + 1;
            que.push_back(v2);
        }
    }

    cout << dist[0] << endl;
}
