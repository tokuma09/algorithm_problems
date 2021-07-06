#include <iostream>

using namespace std;

// &で参照渡しにすることで全ケースのカウント可能
// 残りは値渡しなので
// pop_backの仕組みがいらない
void dfs(long long N, long long A, int flag, long long &count)
{

    // 終点条件
    if (A > N)
    {
        return;
    }

    // 3, 5, 7をすべて使っていればカウントアップ
    if (flag == 0b111)
    {
        ++count;
    }

    //3を付け加えるケースの再帰
    dfs(N, 10 * A + 3, flag | 0b001, count);

    //5を付け加えるケースの再帰
    dfs(N, 10 * A + 5, flag | 0b010, count);

    //7を付け加えるケースの再帰
    dfs(N, 10 * A + 7, flag | 0b100, count);
}

int main()
{

    // 入力
    long long N;
    cin >> N;

    // カウント
    long long count = 0;

    // 実際に計算
    dfs(N, 0, 0, count);

    cout << count << endl;
}
