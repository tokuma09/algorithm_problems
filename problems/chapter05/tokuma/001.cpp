#include <iostream>
#include <vector>

using namespace std;

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
    }
}

int main()
{
    //入力
    int N;
    cin >> N;

    // rewardベクトル
    vector<vector<int>> a(N, vector<int>(3));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> a[i][j];
        }
    }

    // dpテーブル
    // それまでのmaxの値とその前に何を使ったのかを入れるベクトルにする
    // matrixにする
    // そのmatrixの要素がaならb,cをやる
    vector<vector<int>> dp(N + 1, vector<int>(3, -1));

    // 初期条件の設定
    dp[0] = vector<int>(3, 0);

    // 日付のループ
    for (int i = 0; i < N; ++i)
    {
        // 翌日に行動する選択肢
        for (int j = 0; j < 3; ++j)
        {

            // 当日に行動した選択肢
            for (int k = 0; k < 3; ++k)
            {
                // 当日と翌日の行動が一致するケースは除く
                if (j == k)
                {
                    continue;
                }

                // 当日にkを選択していて、翌日jを選ぶとき
                chmax(dp[i + 1][j], dp[i][k] + a[i][j]);
            }
        }
    }

    // 解答
    int res = -1;
    for (int i = 0; i < 3; ++i)
    {
        chmax(res, dp[N][i]);
    }

    cout << res << endl;
}
