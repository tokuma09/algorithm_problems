#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N), b(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> b[i];
    }

    //ソートする
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    // bごとにループ
    for (int j = 0; j < N; ++j)
    {
        // 貪欲にマッチさせる
        // マッチさせたら次のものへ異動
        if (a[i] < b[j])
        {
            ++i;
        }
    }
    cout << i << endl;
}
