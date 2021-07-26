### 8.1
 連結リストのサイズ $N$ に対して $O(N)$.

### 8.2
 $i$ 番目の要素を取得するために連結リストのスタートから順に $i$ まで見ていく, というのを各 $i = 0, 1, ..., N-1$ に対して行うので, $1 + 2 + ... + N = \frac{N(N+1)}{2}$ より計算量は $O(N^2)$.

### 8.3 
 連結リストのサイズを整数でもつ変数を置いておき, `insert`や`erase`操作時に $+1, -1$ するようにする.

### 8.4 
 削除したいノードを $v$ とする. スタートから順に見て次ノードが $v$ であるようなノードを見つけてきて, それの次ノードを $v$ の次ノードにしてから $v$ を削除する. `004.cpp`参照.