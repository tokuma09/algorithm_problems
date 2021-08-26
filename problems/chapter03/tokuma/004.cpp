#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 入力サイズとターゲットを指定
    int N, v;

    cout << "Enter vector size" << endl;
    cin >> N;

    // 対象となるデータを受け取る
    vector<int> a(N);

    cout << "Enter " << N << " values" << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // 最大値最小値を用意する
    int min_val = 200000000;
    int max_val = -200000000;

    for (int i = 0; i < N; ++i)
    {

        // 最小値ならmin_valを更新
        if (a[i] < min_val)
        {
            min_val = a[i];
        }

        // 最大値なら更新
        if (max_val < a[i])
        {
            max_val = a[i];
        }
    }

    cout << "diff: " << max_val - min_val << endl;
}
