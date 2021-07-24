// スタックの実装

#include <iostream>
#include <vector>
using namespace std;

// 連結リストの書くノードを表す自己参照構造体

struct Node
{
    // 1つ前と次のノードのポインタを保有
    Node *prev;
    int x; // ノードに付随している値

    //オブジェクトコンストラクタ
    Node(int x = 1) : prev(NULL), x(x) {}
};

// スタックポインタ, どこに今いるのかを指す
Node *top;

// 空かどうかの判定
bool isEmpty()
{
    return top == NULL;
}

// ノード p の直後にノード v を挿入する
void push(int x)
{
    //新しいノードをつくる
    Node *node = new Node();
    node->x = x;

    //もし空でなければ、topを親にする
    if (!isEmpty())
    {
        node->prev = top;
    }
    // スタック用のポインタのいちをずらす
    top = node;
}

//
int pop()
{
    // 空ならエラー
    if (isEmpty())
    {
        cout << "Error: no value" << endl;
        return -1;
    }
    else
    {
        // リターンの用意
        int res = top->x;

        // 後にメモリ解放するノードをセット
        Node *fr = top;
        // スタックポインタを前に移動
        top = top->prev;
        // メモリ解放
        free(fr);

        return res;
    }
}
int main(void)
{

    // 動作テスト
    push(1);
    push(2);
    push(3);
    cout << pop() << endl;
}
