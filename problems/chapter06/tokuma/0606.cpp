#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// 円周率
const double PI = acos(-1.0);

// 関数定義
auto func(double t, int A, int B, int C)
{
    return A * t + B * sin(C * PI * t);
};

int main()
{

    int A, B, C;
    cin >> A >> B >> C;

    double left = 0, right = 200;

    for (int iter = 0; iter < 100; ++iter)
    {
        double x = (left + right) / 2;

        if (func(x, A, B, C) <= 100)
        {
            left = x;
        }
        else
        {
            right = x;
        }
    }

    // 小数点第 15 位まで出力 (ヘッダ <iomanip> が必要)
    cout << fixed << setprecision(15) << left << endl;
}
