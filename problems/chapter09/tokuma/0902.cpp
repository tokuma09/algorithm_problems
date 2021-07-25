#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main()
{

    int a, b;
    string text = "3 4 + 1 2 - *";
    string s; // 区切り文字用
    // 空白区切りのため
    stringstream ss;
    ss << text;

    stack<int> St;

    // 空白を単位としながら、読み込む
    while (ss >> s)
    {
        if (s == "+")
        {
            b = St.top();
            St.pop();
            a = St.top();
            St.pop();
            St.push(a + b);
        }
        else if (s == "-")
        {
            b = St.top();
            St.pop();
            a = St.top();
            St.pop();
            St.push(a - b);
        }
        else if (s == "*")
        {
            b = St.top();
            St.pop();
            a = St.top();
            St.pop();
            St.push(a * b);
        }
        else if (s == "/")
        {
            b = St.top();
            St.pop();
            a = St.top();
            St.pop();
            St.push(a / b);
        }
        else
        {
            St.push(atoi(s.c_str()));
        }
    }

    cout << St.top() << endl;
}
