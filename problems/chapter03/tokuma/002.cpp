#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 前準備
    int N;
    cout << "Enter vector size" << endl;
    cin >> N;

    int v;
    cout << "Enter target value" << endl;
    cin >> v;

    vector<int> a(N);
    cout << "Enter " << N << " values" << endl;

    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    // 実際の探索
    int num_match = 0;

    // 全部探索して、一致するものがあればカウントアップ
    for (int i = 0; i < N; ++i)
    {

        if (a[i] == v)
        {
            num_match += 1;
        }
    }

    cout << "Answer: " << num_match << endl;
}
