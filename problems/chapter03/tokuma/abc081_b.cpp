#include <iostream>
#include <vector>

using namespace std;

int num_divisible(int val, int divisor)
{

    int num = 0;

    while (val % divisor == 0)
    {
        // 割り切れるときにはその数で割る
        val /= divisor;

        // カウントアップ
        num += 1;
    }

    return num;
}

int main()
{
    int N;

    // cout << "Enter number of values" << endl;
    cin >> N;

    vector<int> a(N);
    // cout << "Enter " << N << " values" << endl;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // 実際にカウントしてみるもの, 大きな値
    int res = 100000000;

    for (int i = 0; i < N; ++i)
    {
        int num = num_divisible(a[i], 2);

        if (num < res)
        {
            res = num;
        }
    }

    // cout << "Result:" << res << endl;
    cout << res << endl;
}
