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
    vector<vector<bool>> memo(N + 1, vector<bool>(W + 1, false));

    //初期条件
    memo[0][0] = true;

    // 重さに関するループ, i番目までの候補で考える
    for (int i = 0; i < N; ++i)
    {
        // ここで合計に対してのループ
        for (int w = 0; w <= W; ++w)
        {

            // i+1番目を使わないとき
            // 事前にチェックしておく
            if (memo[i][w] == true)
            {
                memo[i + 1][w] = true;
            }

            // i+1番目を使うとき
            // w+ (a[i]の倍数)は必ずクリアするので、それをチェックしておく
            if ((memo[i + 1][w] == true) && (w + a[i] <= W))
            {
                memo[i + 1][w + a[i]] = true;
            }
        }
    }

    if (memo[N][W] == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
