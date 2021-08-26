#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int K, N;

    cout << "Enter upper-bound" << endl;
    cin >> K;

    cout << "Enter target value" << endl;
    cin >> N;

    int Z;

    // 解答格納
    int res = 0;

    // XとYでループしてZ= N-X-Yが
    // 0 <= N-X-Y<=Kの範囲に入るかどうかを確認する
    for (int X = 0; X <= K; ++X)
    {
        for (int Y = 0; Y <= K; ++Y)
        {
            Z = N - X - Y;

            if ((0 <= Z) & (Z <= K))
            {
                res += 1;
            }
        }
    }

    cout << "Result: " << res << endl;
}
