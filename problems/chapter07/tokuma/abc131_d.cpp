#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Interval = pair<long long, long long>;

// 区間を終点時間で比較
bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    // 入力
    long long N;
    cin >> N;
    // A: 終わるまでの時間
    // B: 締め切り
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> inter[i].first >> inter[i].second;
    }

    //締め切りでソートする
    sort(inter.begin(), inter.end(), cmp);

    // 経過時間と達成可能かのフラグ
    long long elasped = 0;
    bool flag = true;

    for (int i = 0; i < N; ++i)
    {
        // その作業をするために累積時間
        elasped += inter[i].first;

        // 締切オーバーしているかのチェック
        if (inter[i].second < elasped)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
