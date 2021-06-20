#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 入力サイズとターゲットを指定
    int N, v;

    cout << "decide vector size" << endl;
    cin >> N;

    cout << "decide target value" << endl;
    cin >> v;

    // 対象となるデータを受け取る
    vector<int> a(N);

    cout << "define " << N << " values" << endl;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // ターゲットのいちを判定するためのもの
    int found_id = -1;

    for (int i = 0; i < N; ++i)
    {
        if (a[i] == v)
        {
            found_id = i;
        }
    }

    cout << found_id << endl;
}
