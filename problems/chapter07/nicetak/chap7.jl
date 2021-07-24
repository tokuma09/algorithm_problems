### A Pluto.jl notebook ###
# v0.15.1

using Markdown
using InteractiveUtils

# ╔═╡ ad211b82-c497-4081-8ff4-4e82d43a3db9
using PlutoUI

# ╔═╡ 17677ae6-e264-11eb-3006-77b002930765
md"""
# Chapter 7
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ ad98b4fc-f7d9-4917-896d-a3fa783f0ebf
md"""
## 7.1 
 $N$個の整数$a_0, a_1, \dots, a_{N-1}$と, $N$個の整数$b_0, b_1, \dots, b_{N-1}$が与えられます. $a_0, a_1, \dots, a_{N-1}$から何個かと$b_0, b_1, \dots, b_{N-1}$から何個かを選んでペアを作ります, ただし各ペア$(a_i, b_j)$は$a_i < b_j$を満たさなければなりません. 最大で何ペア作れるかを$O(N \log N)$で求めるアルゴリズムを設計してください.
"""

# ╔═╡ db0fd574-7e1f-466c-97e6-52217e95adbb
function f₁(as, bs)
	N = length(as)
	sort!(as)
	sort!(bs)
	
	ans = 0
	for b in bs
		ans += searchsortedfirst(as, b) - 1
	end
	
	return ans
end

# ╔═╡ 72ebfd16-144f-4034-a407-22e265fc8236
with_terminal() do
	N = 5
	as = rand(1:N, N)
	bs = rand(1:N, N)
	
	@show as
	@show bs
	@show f₁(as, bs)
end

# ╔═╡ 00000000-0000-0000-0000-000000000001
PLUTO_PROJECT_TOML_CONTENTS = """
[deps]
PlutoUI = "7f904dfe-b85e-4ff6-b463-dae2292396a8"

[compat]
PlutoUI = "~0.7.9"
"""

# ╔═╡ 00000000-0000-0000-0000-000000000002
PLUTO_MANIFEST_TOML_CONTENTS = """
# This file is machine-generated - editing it directly is not advised

[[Base64]]
uuid = "2a0f44e3-6c83-55bd-87e4-b1978d98bd5f"

[[Dates]]
deps = ["Printf"]
uuid = "ade2ca70-3891-5945-98fb-dc099432e06a"

[[InteractiveUtils]]
deps = ["Markdown"]
uuid = "b77e0a4c-d291-57a0-90e8-8db25a27a240"

[[JSON]]
deps = ["Dates", "Mmap", "Parsers", "Unicode"]
git-tree-sha1 = "81690084b6198a2e1da36fcfda16eeca9f9f24e4"
uuid = "682c06a0-de6a-54ab-a142-c8b1cf79cde6"
version = "0.21.1"

[[Logging]]
uuid = "56ddb016-857b-54e1-b83d-db4d58db5568"

[[Markdown]]
deps = ["Base64"]
uuid = "d6f4376e-aef5-505a-96c1-9c027394607a"

[[Mmap]]
uuid = "a63ad114-7e13-5084-954f-fe012c677804"

[[Parsers]]
deps = ["Dates"]
git-tree-sha1 = "c8abc88faa3f7a3950832ac5d6e690881590d6dc"
uuid = "69de0a69-1ddd-5017-9359-2bf0b02dc9f0"
version = "1.1.0"

[[PlutoUI]]
deps = ["Base64", "Dates", "InteractiveUtils", "JSON", "Logging", "Markdown", "Random", "Reexport", "Suppressor"]
git-tree-sha1 = "44e225d5837e2a2345e69a1d1e01ac2443ff9fcb"
uuid = "7f904dfe-b85e-4ff6-b463-dae2292396a8"
version = "0.7.9"

[[Printf]]
deps = ["Unicode"]
uuid = "de0858da-6303-5e67-8744-51eddeeeb8d7"

[[Random]]
deps = ["Serialization"]
uuid = "9a3f8284-a2c9-5f02-9a11-845980a1fd5c"

[[Reexport]]
git-tree-sha1 = "5f6c21241f0f655da3952fd60aa18477cf96c220"
uuid = "189a3867-3050-52da-a836-e630ba90ab69"
version = "1.1.0"

[[Serialization]]
uuid = "9e88b42a-f829-5b0c-bbe9-9e923198166b"

[[Suppressor]]
git-tree-sha1 = "a819d77f31f83e5792a76081eee1ea6342ab8787"
uuid = "fd094767-a336-5f1f-9728-57cf17d0bbfb"
version = "0.2.0"

[[Unicode]]
uuid = "4ec0a83e-493e-50e2-b9ac-8f72acf5a8f5"
"""

# ╔═╡ Cell order:
# ╟─17677ae6-e264-11eb-3006-77b002930765
# ╟─ad211b82-c497-4081-8ff4-4e82d43a3db9
# ╟─ad98b4fc-f7d9-4917-896d-a3fa783f0ebf
# ╠═db0fd574-7e1f-466c-97e6-52217e95adbb
# ╟─72ebfd16-144f-4034-a407-22e265fc8236
# ╟─00000000-0000-0000-0000-000000000001
# ╟─00000000-0000-0000-0000-000000000002
