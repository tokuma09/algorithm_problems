#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 自分の前後左右の位置を表現
// 上下左右への動きを表すベクトル
const vector<int> move_x = {1, 0, -1, 0};
const vector<int> move_y = {0, 1, 0, -1};
int main()
{
    // 入力
    int H, W; // 縦の長さ, 横の長さ
    cin >> H >> W;

    // 1行ずつ迷路を用意
    vector<string> laby(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> laby[i];
    }
    // スタートとゴールの座標
    pair<int, int> start, end;
    // firstがx軸, secondがy軸
    start.first = -1, start.second = -1;
    end.first = -1, end.second = -1;

    // 座標特定
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (laby[i][j] == 'S')
            {
                start.first = i;
                start.second = j;
            }
            if (laby[i][j] == 'G')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    queue<pair<int, int>> que;                       // 検索キュー
    vector<vector<int>> dist(H, vector<int>(W, -1)); // スタートからの距離

    // 初期状態の設定
    que.push({start.first, start.second});
    dist[start.first][start.second] = 0;

    // bfs
    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();

        //隣接頂点を見る
        for (int dir = 0; dir < 4; ++dir)
        {
            // 次の頂点を探る
            int next_x = move_x[dir] + x;
            int next_y = move_y[dir] + y;

            // 迷宮外はスキップ
            if (next_x < 0 || H <= next_x || next_y < 0 || W <= next_y)
            {
                continue;
            }
            // 行き止まりはスキップ
            if (laby[next_x][next_y] == '#')
            {
                continue;
            }

            // 探索済みでなければ追加
            if (dist[next_x][next_y] == -1)
            {
                dist[next_x][next_y] = dist[x][y] + 1;
                que.push(pair<int, int>(next_x, next_y));
            }
        }
    }
    cout << dist[end.first][end.second] << endl;
}
