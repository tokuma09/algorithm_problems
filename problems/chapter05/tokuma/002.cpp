#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // サイズ
    int N;
    cin >> N;

    // 重さx
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // 合計
    int W;
    cin >> W;

    // メモ
    vector<vector<int>> memo(N + 1, vector<int>(W + 1, -1));

    //初期条件
    memo[0] = vector<int>(W + 1, 0);
    memo[0][0] = 1;

    // 重さに関するループ, i番目までの候補で考える
    for (int i = 1; i < N + 1; ++i)
    {
        // ここで合計に対してのループ
        for (int w = 0; w < W + 1; ++w)
        {
            // i番目を使う場合
            // 添字対応のため-1しておく
            if (0 <= w - a[i - 1])
            {

                // メモでtrueを返すなら1を入れる
                if (memo[i - 1][w - a[i - 1]] == 1)
                {
                    memo[i][w] = 1;
                }
            }

            // i番目を使わない場合でtrueなら入れる
            if (memo[i - 1][w] == 1)
            {
                memo[i][w] = 1;
            }

            // メモ化されていなくて、かつだめだったら0を入れる
            if (memo[i][w] == -1)
            {
                memo[i][w] = 0;
            }
        }
    }

    if (memo[N][W] == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
