#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60;
int main()
{

    long long N, K;
    cin >> N >> K;

    vector<long long> a(N), b(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> b[i];
    }

    // ソートしておく
    sort(b.begin(), b.end());

    long long left = 0, right = INF;

    //2分探索
    while (right - left > 1)
    {

        // この値を目標にしたときにこれより小さい値が何個あるのか調べていく
        long long x = (left + right) / 2;

        long long cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            cnt += upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
        }

        // もしK個より少ないなら、より大きい部分を探索
        if (cnt < K)
        {
            left = x;
        }
        else
        {
            right = x;
        }
    }
    cout << right << endl;
}
