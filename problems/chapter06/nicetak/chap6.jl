### A Pluto.jl notebook ###
# v0.14.8

using Markdown
using InteractiveUtils

# ╔═╡ 8dedd8b2-0f0a-4523-8503-3c8405b3ef64
using PlutoUI

# ╔═╡ cad5438e-df75-11eb-1882-e384f5a8554c
md"""
# Chapter 6
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ c1e55426-349f-4419-aacc-756b9db75ce5
md"""
## 6.1
どの２要素も互いに相異なる$N$要素からなる整数列$a_0, a_1, \dots, a_{N-1}$が与えられます.
$i = 0, 1, \dots, N-1$に対して, $a_i$が全体の中で何番目に小さい値であるかを$O(N \log N)$で求めるアルゴリズムを設計してください.
"""

# ╔═╡ bb6c9fc1-1087-41c2-9685-38734bda7abe
md"""
**答** 
Juliaの標準ソートアルゴリズム`sort`が$O(N \log N)$で動作し, 各$a_i$がソート列のどの位置に挿入されるかは`searchsortedfirst`によって$O(\log N)$で調べられ(二分探索より), それを$N$回繰り返せばよい.
"""

# ╔═╡ bfc7a793-e646-42bf-9f93-246ffe0f10f1
function f₁(as)
	as_sorted = sort(as)
	return [searchsortedfirst(as_sorted, a) for a in as]
end

# ╔═╡ cdda7a2e-a79b-4585-b39a-c7efc39af10e
md"""
なお, Juliaには標準でこの座標圧縮を行う関数`sortperm`が実装されている.
"""

# ╔═╡ db96c894-8e17-46c4-867b-ce8628c80939
with_terminal() do
	as = [12, 43, 7, 15, 9]
	println("Given as = $as,\n")
	@show f₁(as)
	@show sortperm(as)
end

# ╔═╡ 0b3ae17a-cbed-4b12-b9fb-1ff125ae7774
md"""
 $N = 100$に対して, $M = 10000$回の試行を行う計算時間を比べると, `sortperm`がやや早い.
"""

# ╔═╡ 56f632a0-e7c8-46da-a9b2-34bb96f053a4
begin
	function time₁(A, f)
		M = size(A)[2]

		for i in 1:M
			f(A[:, i])
		end
	end
	
	N, M = 100, 10000
	A = rand(1:N, N, M)
	
	t_f₁ = @timed time₁(A, f₁)
	t_sp = @timed time₁(A, sortperm)
	
	with_terminal() do
		println("Time f₁: $(t_f₁.time)")
		println("Time sortperm: $(t_sp.time)")
	end
end

# ╔═╡ Cell order:
# ╟─cad5438e-df75-11eb-1882-e384f5a8554c
# ╟─8dedd8b2-0f0a-4523-8503-3c8405b3ef64
# ╟─c1e55426-349f-4419-aacc-756b9db75ce5
# ╟─bb6c9fc1-1087-41c2-9685-38734bda7abe
# ╠═bfc7a793-e646-42bf-9f93-246ffe0f10f1
# ╟─cdda7a2e-a79b-4585-b39a-c7efc39af10e
# ╟─db96c894-8e17-46c4-867b-ce8628c80939
# ╟─0b3ae17a-cbed-4b12-b9fb-1ff125ae7774
# ╟─56f632a0-e7c8-46da-a9b2-34bb96f053a4
