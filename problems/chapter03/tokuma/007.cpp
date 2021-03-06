#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;

    cin >> S;
    long long sum_val = 0;
    // bitでどの列に+を入れるかを考える
    // 間だけなので-1
    for (long long bit = 0; bit < (1 << S.length() - 1); ++bit)
    {
        // 文字列そのものを操作するためコピー
        string S_copy = S;
        long long val = 0;

        // 各桁を操作する間なので1だけ引く
        for (long long i = 0; i < (S.length() - 1); ++i)
        {
            // 1がでたら
            if (bit & (1 << i))
            {
                // 1がでたところまでを取り出す
                long long part = stoll(S_copy.substr(0, i + 1));
                // 足し算
                val += part;

                // 足し算した部分は考えなくて良くなるので0で穴埋め
                // 文字列サイズをあわせるためにi+1個の0で文字列の初期化
                string impute(i + 1, '0');
                S_copy.replace(0, i + 1, impute);
            }
        }

        // 最後まで1が出なかったらそこまでの文字を足す
        // もしすでにでていても、そこまでの部分は0で置き換えているので問題ない
        val += stoll(S_copy);
        sum_val += val;
    }
    cout << sum_val << endl;
}
