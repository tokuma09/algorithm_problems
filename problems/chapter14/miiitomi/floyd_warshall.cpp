#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> dp(N, vector<ll>(N, INF));

    for (int e = 0; e < M; e++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for (int v = 0; v < N; v++) dp[v][v] = 0;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int v = 0; v < N; v++) {
        if (dp[v][v] < 0) {
            cout << "Negatibve cycle exists!" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << " ";
            if (dp[i][j] < INF/2) cout << dp[i][j];
            else cout << "INF";
        }
        cout << endl;
    }
}
