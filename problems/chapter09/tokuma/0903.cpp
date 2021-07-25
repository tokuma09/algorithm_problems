#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check_correspondence(string s)
{

    stack<int> St; // 左括弧のインデックスを入れる
    vector<pair<int, int>> ind_pair;

    // 文字列を1文字ずつ調査
    for (int i = 0; i < s.size(); ++i)
    {
        // 左括弧ならスタックに格納
        if (s[i] == '(')
        {
            St.push(i);
        }
        else
        {
            // 左括弧残量がないのであれば、エラー
            if (St.empty())
            {
                cout << "Excess Right" << endl;
                return false;
            }

            // 対応する左括弧インデックスを取り出して、追加
            int t = St.top();
            St.pop();
            ind_pair.push_back({t, i});
        }
    }

    // 最終的にスタックが空になれば正しい
    if (St.empty())
    {
        // 出力する
        for (int i = ind_pair.size() - 1; 0 <= i; --i)
        {

            cout << "(" << ind_pair[i].first << ", " << ind_pair[i].second;
            if (i == 0)
            {
                cout << ")";
            }
            else
            {
                cout << "), ";
            }
        }
        cout << endl;
        return true;
    }
    else
    {
        cout << "Excess Left" << endl;
        return false;
    }
}

int main()
{
    string test1 = "((()())())";
    cout << "test 1 " << test1 << endl;
    check_correspondence(test1);

    string test2 = "())";
    cout << "test 2 " << test2 << endl;
    check_correspondence(test2);

    string test3 = "(()";
    cout << "test 3 " << test3 << endl;
    check_correspondence(test3);
}
