#include <iostream>
#include <vector>

using namespace std;

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}
int main()
{

    // サイズ
    int N;
    cin >> N;

    // 個数
    int k;
    cin >> k;

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
    // その時の使った個数を入れる
    vector<vector<long long>>
        memo(N + 1, vector<long long>(W + 1, 1LL << 50));

    //初期条件
    memo[0][0] = 0;

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

                // i番目を使う場合で条件を満たすのであれば、1を足す
                if (0 <= memo[i - 1][w - a[i - 1]])
                {
                    chmin(memo[i][w], memo[i - 1][w - a[i - 1]] + 1);
                }
            }

            // i番目を使わない場合で条件を満たすときはたさない
            if (0 <= memo[i - 1][w])
            {
                chmin(memo[i][w], memo[i - 1][w]);
            }
        }
    }

    // これで回答をチェック
    if (memo[N][W] <= k)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
