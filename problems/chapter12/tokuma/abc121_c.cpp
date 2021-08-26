#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> v(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }

    // ソート
    sort(v.begin(), v.end());

    long long res = 0;
    int num = 0;

    for (int i = 0; i < N; ++i)
    {
        if (v[i].second < M)
        {
            res += v[i].first * v[i].second;
            num += v[i].second;
            M -= v[i].second;
        }
        else
        {
            res += v[i].first * M;
            num += M;

            break;
        }
    }

    cout << res << endl;
}
