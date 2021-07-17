#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int N;
    cin >> N;

    vector<long long> a(N), b(N), c(N);

    // 入力
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> b[i];
    }
    for (int i = 0; i < N; ++i){
        cin >> c[i];
    }

    // ソート
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());


    // 真ん中を固定して比較していく
    long long res = 0; // 条件を満たすペアをカウント

    for (int j = 0; j < N; ++j){

        // 個数 先頭を指すイテレータからの差分を取れば、個数がきちんと取れる
        // a_i >= b[j]となるようなイテレータを返すので、 1引く
        long long Aj = lower_bound(a.begin(), a.end(), b[j]) - a.begin();

        // こっちは実際に c_i <= b_jとなるような個数を計算し、Nから引く
        long long Cj = N - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());

        // 組み合わせなので掛け算
        res += Aj * Cj;
    }
    cout << res << endl;
}
