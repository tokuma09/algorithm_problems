// WAだったので解説読んだ
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Interval = pair<int, int>;

// 区間をy座標でソート
bool cmp_y(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

bool rev_x(const Interval &a, const Interval &b)
{
    return b.first < a.first;
}
int main()
{
    int N;

    cin >> N;

    vector<Interval> red(N), blue(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> red[i].first >> red[i].second;
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> blue[i].first >> blue[i].second;
    }

    // xで降順ソート
    sort(red.begin(), red.end(), rev_x);
    // yで昇順ソート
    sort(blue.begin(), blue.end(), cmp_y);

    vector<bool> use_red(N, false); // これまでどれを使ったか
    int res = 0;
    //青い点を基準に考える
    for (int j = 0; j < N; ++j)
    {
        for (int i = 0; i < N; ++i)
        {

            // 条件をクリアしたら、利用フラグを立てて、カウント
            // そしてbreakする
            if ((use_red[i] == false) & (red[i].second < blue[j].second) & (red[i].first < blue[j].first))
            {
                use_red[i] = true;
                ++res;
                break;
            }
        }
    }

    cout << res << endl;
}
