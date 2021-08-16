#include <iostream>
#include <vector>

using namespace std;

struct Heap
{
    vector<int> heap;
    Heap(){};

    // ヒープに値xを挿入
    void push(int x)
    {
        heap.push_back(x); //最後尾に挿入

        int i = (int)heap.size() - 1; //挿入された頂点の番号
        while (i > 0)
        {
            int p = (i - 1) / 2; //親の頂点番号
            if (heap[p] >= x)
            {
                break; //自分より大きいのであれば並び替え修了
            }

            heap[i] = heap[p]; // 親と自分を逆転
            i = p;             // インデックス変更
        }
        heap[i] = x; // 最終的なインデックスの部分に値を入れ直す
    }

    // 最大値を取る
    int top()
    {
        if (!heap.empty())
        {
            return heap[0];
        }
        else
        {
            return -1;
        }
    }

    // 最大値を削除
    void pop()
    {
        if (heap.empty())
        {
            return;
        }

        int x = heap.back(); //頂点に持ってくる値
        heap.pop_back();

        int i = 0; // 根からおろしていく
        while (i * 2 + 1 < (int)heap.size())
        {
            // 子頂点同士を比較して大きい方を child1 とする
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] > heap[child1])
            {
                child1 = child2;
            }
            if (heap[child1] <= x)
                break;              // 逆転がなければ終了
            heap[i] = heap[child1]; // 自分の値を子頂点の値にする
            i = child1;             // 自分は下に行く
        }
        heap[i] = x; // x は最終的にはこの位置にもってくる
    }
};
int main(){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    Heap heap_low;
    Heap heap_high;

    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    // 最初のK個をlowに追加
    for (int i = 0; i < K; ++i){
        heap_low.push(a[i]);
    }

    for (int i = K; i < N; ++i){
        // heap_low.top()がK個の中の最も大きい数
        // それ以上のものは無視し、
        // topよりも小さいものはtopと入れ替えする。
        // これによってheapの中は常にその時点までの1-K番目の小さい値が含まれている。
        if (a[i] < heap_low.top()){
            heap_low.pop();
            heap_low.push(a[i]);
        }
    }
    cout << heap_low.top() << endl;
}
