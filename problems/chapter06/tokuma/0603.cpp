#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    long long N, M;
    cin >> N >> M;

    // データの中に0を加える
    // 情報オリンピックの問題では4個まで選ぶという問題なので
    // 0を追加することで、1, 2, 3個選ぶ状況を作る
    vector<long long> P(N);
    for (int i = 0; i < N; ++i){
        cin >> P[i];
    }
    P.push_back(0);

    // Pの中から2つの組み合わせの合計を入れる
    vector<long long> S;
    for (int i = 0; i < P.size(); ++i){
        for (int j = 0; j < P.size(); ++j){
            S.push_back(P[i] + P[j]);
        }
    }

    // 簡単化のためソートする
    sort(S.begin(), S.end());

    // このSの中から2つを選んだときの最大値を調べていく

    long long res = 0;
    // 1つ要素を固定
    for (long long a : S){
        //s_i <= M-aなるイテレータを選ぶ
        auto it = upper_bound(S.begin(), S.end(), M - a);

        // もしもはじめの部分ならもうNGなので飛ばす
        if (it== S.begin()){
            continue;
        }

        // begin分だけ引く
        --it;

        // これまでの値とどちらが大きいか引く
        res = max(res, a + *it);
    }

    cout << res << endl;
}
