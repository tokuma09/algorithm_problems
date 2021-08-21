#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 要素数 5 以下の配列の中央値を返す.
int median5(vector<int> &c) {
    sort(c.begin(), c.end());
    int idx = (int)c.size() / 2;
    return c[idx];
}

// 配列 b の中央値の中央値を再帰的に返す.
int medianOfMedians(vector<int> &b) {
    if ((int)b.size() <= 5) return median5(b);

    vector<int> b_new(((int)b.size() - 1) / 5 + 1);
    for (int i = 0; i < (int)b.size(); i += 5) {
        vector<int> c = vector<int>(b.begin() + i, b.begin() + min(i+5, (int)b.size()));
        b_new[i / 5] = median5(c);
    }
    return medianOfMedians(b_new);
}

// a[start:end] から適切な pivot の index を返す.
int Pivot(vector<int> &a, int start, int end) {
    vector<int> b = vector<int>(a.begin()+start, a.begin()+end);
    int pivot = medianOfMedians(b);
    int pivot_idx = 0;
    for (;; pivot_idx++) {
        if (a[pivot_idx] == pivot) return pivot_idx;
    }
}

int Select(vector<int> &a, int k, int start, int end) {
    int pivot_index = Pivot(a, start, end);
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[end - 1]);

    int i = start;
    for (int j = start; j < end - 1; j++) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[end - 1]);

    if (i == k) {
        return a[i];
    } else if (i < k) {
        return Select(a, k, i + 1, end);
    } else {
        return Select(a, k, start, i);
    }
}

int main() {
    int N, k;
    cin >> N >> k;
    k--;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = Select(a, k, 0, N);
    cout << ans << endl;
}
