// https://atcoder.jp/contests/dp/tasks/dp_n
// ギブアップ
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

const long long INF = 1LL << 60;

int main()
{
    // 入力
    int N;
    cin >> N;

    // サイズ
    vector<long long> c(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> c[i];
    }

    // 累積和！(この問題のポイント)
    vector<long long> S(N + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        S[i + 1] = S[i] + c[i];
    }

    // DPテーブルの用意
    // dp[i][j] 意味 iからj番目までのデータのみを考えたとき
    // スライムが1匹になるまで合体させるのにかかる最小コスト
    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, INF));

    // 初期条件なぜならこの幅で合体はないから
    for (int i = 0; i < N; ++i)
    {
        dp[i][i + 1] = 0;
    }

    // 更新

    // 考える幅をジョジョに小さくしていく
    for (int bet = 2; bet <= N; ++bet)
    {
        // 始点の決定
        for (int i = 0; i + bet <= N; ++i)
        {
            // 対応する終点の決定
            int j = i + bet;

            // 個々の部分は区間分割の最適化と同じ。
            // k番目での分割を考えることで、コストが更に小さくなるか？
            for (int k = i + 1; k < j; ++k)
            {
                // jからiまでの最小コスト
                // [i-k]までを合体させてきたスライムのコスト
                // [k-j]までを合体させてきたスライムのコスト
                // 今回の合体に必要なコストを組み合わせて比較
                chmin(dp[i][j], dp[i][k] + dp[k][j] + (S[j] - S[i]));
            }
        }
    }

    cout << dp[0][N] << endl;
}
