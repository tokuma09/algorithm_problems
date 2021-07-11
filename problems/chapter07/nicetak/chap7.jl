### A Pluto.jl notebook ###
# v0.14.8

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
	i, j = 1, 1
	while i ≤ N
		while j ≤ N
			if as[i] < bs[j]
				ans += 1
				break
			end
			j += 1
		end
		i += 1
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

# ╔═╡ Cell order:
# ╟─17677ae6-e264-11eb-3006-77b002930765
# ╟─ad211b82-c497-4081-8ff4-4e82d43a3db9
# ╟─ad98b4fc-f7d9-4917-896d-a3fa783f0ebf
# ╠═db0fd574-7e1f-466c-97e6-52217e95adbb
# ╟─72ebfd16-144f-4034-a407-22e265fc8236
