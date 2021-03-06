## 8.1

> 連結リストのコード8.6において, 連結リストの各ノードに格納された値を順に出力する関数`printList`の処理に要する計算量を評価してください.

```cpp
for (; cur != nil; cur = cur->next){
    cout << cur->name << " -> ";
}
```
上の部分は$O(N)$で実行可能。


## 8.2
>サイズが$N$の連結リストにおいて, `get(i)`を`head`からスタートして$i$番目の要素を取得する関数とします. この時以下のコードの計算量を求めてください.

```cpp
for (int i = 0; i < N; ++i){
    cout << get(i) <<endl;
}
```
連結リストを最初の要素からポイントに従いi番目までのデータを順番に取得する必要がある。
したがって、`get(i)`の計算量は$O(N)$であり、
これを$N$回繰り返すことから計算量は$O(N^2)$

## 8.3
> 連結リストにおいて, サイズを$O(1)$で取得できるようにする方法を述べてください.

ノードの構造体にサイズを表すメンバ変数`size`を追加する。(初期値=0)
`code8.4`の例であれば、挿入するたびにすべてのノードの`size`に1を足す。


## 8.4
> 単方向連結リストにおいて, 特定のノード$v$を削除する方法を述べてください. ただし, $O(N)$の計算量を要してもよいものとします.

連結リストを先頭から順に進み、以下の2つのノードを取得する。
- ポインタが`v`を示すノード`a`
- `v`のポインタが示すノード`b`

ノード`a`のポインタがノード`b`を示すように変更すれば、特定のノード`v`を削除したことになる。($O(1)$の処理)

条件に当てはまるノードかどうかの判定回数は$O(N)$であるから、全体の計算時間は$O(N)$である。


## 8.5

> $N$個の相違なる整数, $a_0,a_1, \ldots, a_{N-1}$と$M$個の相違なる整数, $b_0,b_1, \ldots, b_{M-1}$が与えられます。$a$と$b$とで共通する整数の個数を平均的に$O(N+M)$の計算量で求めるアルゴリズムを設計してください。

- step1: ハッシュテーブルに$a_0,a_1, \ldots, a_{N-1}$を挿入する。(平均的には$O(N)$)

- step2: 各$b_i$がハッシュテーブル内に存在するか検索する(平均的には$O(M)$)
    - 存在する場合をカウントしていく

step2でカウントしたものが解となる。


## 8.6

> $N$個の整数, $a_0,a_1, \ldots, a_{N-1}$と$M$個の整数, $b_0,b_1, \ldots, b_{M-1}$が与えられます。$a_i = b_j$となるような添字の組の個数を平均的に$O(N+M)$の計算量で求めるアルゴリズムを設計してください。

- step1. $a_0,a_1, \ldots, a_{N-1}$を用いて、keyを$a_i$, valueをその個数とするような連想配列を構築する。(平均$O(N)$の処理)

- step2: 各$b_i$が連想配列のkeyに存在する検索する(平均的には$O(M)$)
  - 存在する場合はそのvalueを足し上げる

step2でカウントしたものが解となる。


## 8.7
>  $N$個の整数$a_0, a_1, \dots, a_{N-1}$と, $N$個の整数$b_0, b_1, \dots, b_{N-1}$が与えられます. 2組の整数列からそれぞれ1個ずつ整数を選んで和を$K$とすることができるかどうかを, 平均的に$O(N)$の計算量で判定するアルゴリズムを設計してください.　なお, 6.6節では, 類似の問題に対する, 二分探索法に基づいた$O(N \log N)$の計算量のアルゴリズムを示しました.

- step1: ハッシュテーブルに$a_0,a_1, \ldots, a_{N-1}$を挿入する。(平均的には$O(N)$)
- step2: $K-b_i$がハッシュテーブルに含まれるかをN回確認する(平均的には$O(N)$)
    - 少なくとも１つ含まれていれば"Yes", そうでなければ"No"を返す。

これによって平均的には$O(N)$で計算可能。
