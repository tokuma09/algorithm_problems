#include <iostream>
#include <string>
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
    // 入力
    string S, T;
    cin >> S >> T;

    // 編集距離の類題
    // dp[i][j]はそこまでで何回削除操作するかどうかを示す→この方法だと難しい(２つとも削除するコストがはいる)
    // dp[i][j]はそこまでの最大の長さにする

    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));

    // Sのループ
    for (int i = 0; i < S.size(); ++i)
    {
        for (int j = 0; j < T.size(); ++j)
        {
            // もし同じ文字であれば、最大文字の長さ足す1
            if (S[i] == T[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            // 違う文字であれば、そこまでの最大の長さを入れる
            else
            {
                chmax(dp[i + 1][j + 1], dp[i + 1][j]);
                chmax(dp[i + 1][j + 1], dp[i][j + 1]);
            }
        }
    }

    string res;
    int i = S.size() - 1;
    int j = T.size() - 1;

    // backwardにdpテーブルを探索する
    while (i >= 0 && j >= 0)
    {
        // 文字が一致していれば、足す
        if (S[i] == T[j])
        {
            // 遡るので、今までのものの前に足す
            res = S[i] + res;
            --i;
            --j;
        }
        // 文字が一致しないのであれば、dpの値が減らない方に移動する。

        else if (dp[i + 1][j] == dp[i + 1][j + 1])
        {
            --j;
        }
        else
        {
            --i;
        }
    }

    cout << res << endl;
}
