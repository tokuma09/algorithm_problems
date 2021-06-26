#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

// i個までのデータでwを達成できるかを判定する関数
int func(int i, int w, const vector<int> &a)
{
    // ベースケース
    if (i == 0)
    {

        if (w == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // すでに結果を計算済みであれば、それを返す
    if (memo[i][w] != -1)
    {
        return memo[i][w];
    }

    // まだ計算していないときは
    // i-1個のデータをどのように使うかを2パターンに分けて評価

    // a[i-1]を選んだときに部分和がある場合
    if (func(i - 1, w - a[i - 1], a))
    {
        return memo[i][w] = 1;
    }

    // a[i-1]を選ばなかったときに部分和があるとき
    if (func(i - 1, w, a))
    {
        return memo[i][w] = 1;
    }

    // 部分和がない場合
    return memo[i][w] = 0;
}
int main()
{
    // 入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // メモのサイズ決定
    // N個から0個までのデータを考える必要があるのでN+1のサイズ
    // 0からWまでカバーする必要があるのでW+1のサイズ
    memo.assign(N + 1, vector<int>(W + 1, -1));

    if (func(N, W, a))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
