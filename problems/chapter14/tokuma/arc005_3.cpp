#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
// 無限大を表す値
const int INF = 1 << 29;
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
            if (laby[i][j] == 's')
            {
                start.first = i;
                start.second = j;
            }
            if (laby[i][j] == 'g')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    deque<pair<int, int>> que;                        // 検索キュー
    vector<vector<int>> dist(H, vector<int>(W, INF)); // スタートからの距離

    // 初期状態の設定
    que.push_back({start.first, start.second});
    dist[start.first][start.second] = 0;

    // bfs
    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop_front();

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

            // 行き止まりであれば、ブロックを壊す。
            if (laby[next_x][next_y] == '#')
            {
                // コストが少なければ更新
                // コストがかかる部分は後から検索
                if (dist[next_x][next_y] > dist[x][y] + 1)
                {
                    dist[next_x][next_y] = dist[x][y] + 1;
                    que.push_back(pair<int, int>(next_x, next_y));
                }
            }
            else
            {
                // これまでのに比べてコストが少なければ、更新
                // かつ、コストのかからない部分を先に検索
                if (dist[next_x][next_y] > dist[x][y])
                {
                    dist[next_x][next_y] = dist[x][y];
                    que.push_front(pair<int, int>(next_x, next_y));
                }
            }
        }
    }

    if (dist[end.first][end.second] <= 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
