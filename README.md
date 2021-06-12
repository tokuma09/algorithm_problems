# Algorithm and data structures

[問題解決力を鍛える!アルゴリズムとデータ構造](https://www.amazon.co.jp/dp/4065128447)の章末問題を解く。



以下の言語が実行可能なdocker環境を用意
- C++
- python
- julia



### Tips

**pythonインタープリタ起動**
- `python3`

**juliaインタープリタ起動**
- `julia`


**C++の実行方法**

- コンパイル: `g++ -std=c++14 {file}.cpp`
- 実行: `./a.out`

### AtCoder Sample Test
#### 1. 準備
以下の内容の`.env`ファイルをホームディレクトリ直下に用意する
```
ATCODER_USER=hoge
ATCODER_PASS=hogehoge
```

#### 2. ログイン
```
sh cplogin.sh
```

#### 3. テスト (Python/Julia)
`abc***_*.py`か`abc***_*.jl`を開いた状態で<br>
<kbd>command</kbd> + <kbd>chift</kbd> + <kbd>B</kbd> <br>
ファイル名からAtCoderの該当問題のサンプルケースを自動取得し, テストする.

#### 4. デバッグ
ディレクトリ直下に任意の入力を記述した`input.txt`を用意する.

##### Python
<kbd>F5</kbd>を押すと, `input.txt`を標準入力としてデバッガーが起動する.

##### Julia
<kbd>F5</kbd>を押すと, デバッガーが起動するが標準入力は手打ちする必要.