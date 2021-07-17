#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 無限大を表す値
const long long INF = 1LL<<50;

int main(){

    // 入力
    int N, M;
    cin >> N >> M;

    // ソートされるひつようなし
    vector<long long> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }

    long long left = 0, right = INF;

    // すべての間隔をx以上にしてM個の小屋を選べるかという判定問題に読み替える
    while (right-left >1){
        long long x = (left + right) / 2;

        int cnt = 1; // 最初の小屋は選ぶので初期化
        int prev = 0; // 前回のインデックス
        for (int i = 0; i < N; ++i){
            // 一直線なので、その間だけ見ていればよい。
            if (a[i] - a[prev]>=x){
                ++cnt;
                prev = i;
            }
        }
        // 2分探索の更新
        // M個以上あるのであれば、もっと広い範囲を考える
        if (M <= cnt){
            left = x;
        }
        else{
            right = x;
        }
    }

    cout << left << endl;
}
