#include <iostream>
using namespace std;
int main()
{
  string s;
  cin >> s;

  // 3文字制約あるので、素直に分ければ良い
  if (s == "AAA" || s == "BBB")
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
