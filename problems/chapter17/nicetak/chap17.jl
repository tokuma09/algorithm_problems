### A Pluto.jl notebook ###
# v0.16.1

using Markdown
using InteractiveUtils

# ╔═╡ 7bba9ce0-1efe-11ec-2557-b9c38d2fbc38
md"""
# Chapter 17
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ d7594aeb-a318-4cf1-9ee0-e22512aa4681
md"""
## 17.1
ハミルトンサイクル問題がNPに属することを示してください.
"""

# ╔═╡ 645f0723-2329-4f5b-ae46-f1709b86ac38
md"""
**解答**

ハミルトンサイクルの解の候補 $p$ が存在するとして, これがハミルトンサイクルであることを確かめるには

- すべての頂点を通ること
- 合法的な経路であること

を確かめる必要がある. 解候補が$|V|$より長いときは, 自明にハミルトンサイクルでないことが確かめられるので,　たかだか $|V|$ の長さの解候補を見れば良い. このとき, 解候補の順番にたどっていけば, すべての頂点を通ることは自明に確かめられる. 合法的な経路であることは, 解候補の示すある頂点に対して, 次の頂点への辺があることを確かめればよいので, 一つの頂点に対して最大で $|V|$ の長さを見ればよいので, $O(|V|^2)$.

"""

# ╔═╡ 7063faec-9747-443a-8339-dd792109ccb5
md"""
## 17.2
グラフ $G = (V, E)$ と正の整数 $k$ があたえられたときに, $G$ がサイズ $k$ 以上の完全グラフを部分グラフとして含むかどうかを判定する問題を**クリーク問題**とよびます. クリーク問題がNPに属することを示してください.
"""

# ╔═╡ 6bae3ae3-6488-43ae-9548-d9e6a74647ff
md"""
**解答**

解候補は部分グラフである必要があるため, 入力は多項式長である必要があり, これは多項式時間で判定できる.
今, 完全グラフの解候補 $G' = (V', E')$ が与えられているとする. これが部分グラフであることを確かめるためには, 各 $e \in E'$ が $E$ に含まれていることを確かめればよいので, $O(|E|^2)$.
また, これが完全グラフであることを確かめるためには, すべての頂点がすべての他頂点に対して辺を持つことを確かめればよい. 一つの頂点に対して最大で $|V| - 1$ の辺が $E'$ に含まれているか確かめればよいので, $O(|V|^2|E|)$.
"""

# ╔═╡ d7cf1c75-c8de-4f91-9eb4-2c43c0a6df4b
md"""
## 17.3
安定集合問題がNP完全であることを利用して, クリーク問題もNP完全であることを示してください.
"""

# ╔═╡ 67708d53-4285-4025-9ac3-aea1902cafe6
md"""
**解答**

グラフ $G$ の頂点の部分集合 $S$ が安定集合であることは, 補グラフ $\bar{G}$ において, $S$ が完全グラフであることと同値である. したがって, サイズ $k$ 以上の安定集合が存在することと, 補グラフ $\bar{G}$ においてサイズ $k$ 以上の完全グラフが存在することは同値である. 補グラフの構成は自明に多項式時間 $O(|V|^2)$ で可能なので, クリーク問題は安定集合問題に多項式還元される. 
"""

# ╔═╡ Cell order:
# ╟─7bba9ce0-1efe-11ec-2557-b9c38d2fbc38
# ╟─d7594aeb-a318-4cf1-9ee0-e22512aa4681
# ╟─645f0723-2329-4f5b-ae46-f1709b86ac38
# ╟─7063faec-9747-443a-8339-dd792109ccb5
# ╟─6bae3ae3-6488-43ae-9548-d9e6a74647ff
# ╟─d7cf1c75-c8de-4f91-9eb4-2c43c0a6df4b
# ╟─67708d53-4285-4025-9ac3-aea1902cafe6
