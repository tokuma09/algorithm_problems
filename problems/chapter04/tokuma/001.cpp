#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long tribo(int N)
{
    if (N == 0)
    {
        return 0;
    }
    else if (N == 1)
    {
        return 0;
    }
    else if (N == 2)
    {
        return 1;
    }

    if (memo[N] != -1)
    {
        return memo[N];
    }

    return memo[N] = tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main()
{

    int N;
    cin >> N;
    memo.assign(N + 1, -1);
    tribo(N);

    for (int i = 3; i <= N; ++i)
    {
        cout << i << "項目: " << memo[i] << endl;
    }
}
