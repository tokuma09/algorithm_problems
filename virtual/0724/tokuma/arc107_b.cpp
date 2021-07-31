#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    long long res = 0;

    for (long long a = 1; a <= N; ++a){
        for (long long b = 1; b <= N; ++b){

            long long temp = K - (a + b);
            if (2 *N < abs(temp)){
                break;
            }

            for (long long c = 1; c <= N; ++c)
            {
                if ((1<= (- temp - c)) &&((-temp - c ) <=N)){
                        ++res;
                    }
            }
        }
    }

    cout << res << endl;
}
