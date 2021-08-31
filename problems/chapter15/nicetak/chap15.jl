### A Pluto.jl notebook ###
# v0.15.1

using Markdown
using InteractiveUtils

# ╔═╡ 1a1e0d42-0a3a-11ec-2a0b-fdb6a66c334a
md"""
# Chapter 15
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ a2374e54-6385-4e09-83fc-6933087d0bb2
md"""
## 15.1
15.4.3節で紹介した「最小全域木の基本カットセットに関する性質」を証明してください.
"""

# ╔═╡ f29af91b-606e-4357-b542-9a6f4624a58e
md"""
> ##### 最小全域木の基本カットセットに関する性質
> 連結な重み付き無向グラフ$G$において, $T$を最小全域木とします. $T$に含まれる辺$e$を1つとって, $T, e$に関する基本カットセットを$C$とします. このとき, $C$に含まれる辺のうち, 辺$e$は重みが最小の辺となっています.
"""

# ╔═╡ 4b3556c3-2fb5-4871-b4b2-a1aa9dfdee4d
md"""
 $C$に含まれる任意の辺$f$をとったとき,

$T^{\prime} = T - e + f$

なる$T^{\prime}$も全域木である. $T$が最小全域木である仮定から,

$w(T) \le w(T^{\prime}) = w(T) - w(e) + w(f)$
$\therefore w(e) \le w(f)$

これは任意の$f \in C$に対して成り立つので, 辺$e$の重みは$C$のうち最小である.

"""

# ╔═╡ Cell order:
# ╟─1a1e0d42-0a3a-11ec-2a0b-fdb6a66c334a
# ╟─a2374e54-6385-4e09-83fc-6933087d0bb2
# ╟─f29af91b-606e-4357-b542-9a6f4624a58e
# ╟─4b3556c3-2fb5-4871-b4b2-a1aa9dfdee4d
