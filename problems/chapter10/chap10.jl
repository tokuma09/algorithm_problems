### A Pluto.jl notebook ###
# v0.14.8

using Markdown
using InteractiveUtils

# ╔═╡ fc872510-e7b7-11eb-0f83-ed2e18af538f
md"""
# Chapter 10
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ a6075125-eb1f-4486-9e51-185ff559dbcd
md"""
## 10.1
頂点数が $N$ の二分木において, 高さが $N-1$ となるような例をあげてください.

"""

# ╔═╡ 12155e72-f81e-4506-bb4a-087144245cee
md"""
**答.** 北斗神拳の継承者(一子相伝のため)
"""

# ╔═╡ a1da9aaa-f90b-4f67-95df-f79ff214dad5
md"""
## 10.2
空のヒープに3個の整数5, 6, 1をこの順に挿入して得られるヒープについて, 配列で表した時の様子を示してください.

"""

# ╔═╡ f05593a8-cdd7-4ae0-bfe9-6d70a17c356d
md"""
**答.** [6, 5, 1]
"""

# ╔═╡ 0a789e1a-f359-445a-bacf-f5bebdbf91f3
md"""
## 10.3
空のヒープに7個の整数5, 6, 1, 2, 7, 3, 4をこの順に挿入して得られるヒープについて, 配列で表したときの様子を示してください.
"""

# ╔═╡ 7a15992c-8c54-41cf-bd3f-4bb657b922ed
md"""
**答.** [7, 6, 4, 2, 5, 1, 3]
"""

# ╔═╡ 2c6c91c2-9c7d-4ae2-9d0d-f66e891845bd
md"""
## 10.4
強平衡二分木の高さが$h = O(\log N)$となることを示してください.
"""

# ╔═╡ e99a2952-e0be-4afb-8ee1-6438828ceb01
md"""
**答.** 高さ$h$段目に入る要素数は$2^h$であり, 強平衡二分木は各階層が全て埋まったら次の段を埋め始める. したがって, 

$2^h \le N < 2^{h+1}$

よって, $h = O(\log N)$.
"""

# ╔═╡ 89478c0a-9a09-4bf6-96a4-d166d184e126
md"""
## 10.5
頂点数が $N$ の木の辺数が $N-1$であることを示してください.
"""

# ╔═╡ c015fddb-a32c-4ade-ba0c-336b0197fc00
md"""
**答.**
$N = 1$の時は自明. 頂点数 $N$ の木の辺数が $N- 1$ と仮定する.
任意の頂点数 $N+1$ の木は, 頂点数 $N$の木に一つの頂点を加えたものである.
この操作の際に増える辺の数は, 木の定義から, 1である.
したがって, 頂点数 $N+1$ の木の辺数は $N$ であり, 帰納法から命題は示された.
"""

# ╔═╡ Cell order:
# ╟─fc872510-e7b7-11eb-0f83-ed2e18af538f
# ╟─a6075125-eb1f-4486-9e51-185ff559dbcd
# ╟─12155e72-f81e-4506-bb4a-087144245cee
# ╟─a1da9aaa-f90b-4f67-95df-f79ff214dad5
# ╟─f05593a8-cdd7-4ae0-bfe9-6d70a17c356d
# ╟─0a789e1a-f359-445a-bacf-f5bebdbf91f3
# ╟─7a15992c-8c54-41cf-bd3f-4bb657b922ed
# ╟─2c6c91c2-9c7d-4ae2-9d0d-f66e891845bd
# ╟─e99a2952-e0be-4afb-8ee1-6438828ceb01
# ╟─89478c0a-9a09-4bf6-96a4-d166d184e126
# ╟─c015fddb-a32c-4ade-ba0c-336b0197fc00
