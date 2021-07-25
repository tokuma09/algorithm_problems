//queueの実装
// スタックの実装

#include <iostream>
#include <vector>
using namespace std;

// 連結リストの書くノードを表す自己参照構造体

struct Node
{
    // 1つ前と次のノードのポインタを保有
    Node *prev, *next;
    int x; // ノードに付随している値

    //オブジェクトコンストラクタ
    Node(int x = 1) : prev(NULL), next(NULL), x(x) {}
};

// 先頭と最後尾を選ぶ
Node *head;
Node *tail;

// 空かどうかの判定
bool isEmpty()
{
    return (head == NULL);
}

void enqueue(int x)
{

    //新しいノードをつくる
    Node *node = new Node();
    node->x = x;

    // もし最初に登録するものであれば、headを設定しておく
    if (head == NULL)
    {
        head = node;
    }
    // もしも要素がこれまでに1つしか入っていなければ、
    // headの次の値としてnodeを追加
    if (head == tail)
    {
        head->next = node;
    }

    if (tail == NULL)
    {
        tail = node;
    }
    else
    {
        // 最後尾に追加する
        node->prev = tail;
        tail->next = node;
        // 最後尾ポインタを動かす
        tail = node;
    }
}

//
int dequeue()
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
        int res = head->x;

        // 後にメモリ解放するノードをセット
        Node *fr = head;
        // headを後ろに移動
        head = head->next;
        // メモリ解放
        free(fr);

        return res;
    }
}
int main()
{

    // 動作テスト
    enqueue(3); // キューに 3 を挿入する {} -> {3}
    enqueue(5); // キューに 5 を挿入する {3} -> {3, 5}
    enqueue(7); // キューに 7 を挿入する {3, 5} -> {3, 5, 7}

    cout << dequeue() << endl; // {3, 5, 7} -> {5, 7} で 3 を出力
    cout << dequeue() << endl; // {5, 7} -> {7} で 5 を出力
    cout << dequeue() << endl;
    cout << dequeue() << endl;
}
