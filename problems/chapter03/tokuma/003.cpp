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

    // 2番目の値まで用意しておく
    int min_val = 200000000;
    int second_val = min_val - 1;

    for (int i = 0; i < N; ++i)
    {

        // 最小値ならmin_valを更新& secondの置き換え
        if (a[i] < min_val)
        {
            second_val = min_val;
            min_val = a[i];
        }

        // 最小値ではないが、暫定で2番目に小さいものよりも小さい時は更新
        else if (a[i] < second_val)
        {
            second_val = a[i];
        }
    }

    cout << "second minimum: " << second_val << endl;
}
