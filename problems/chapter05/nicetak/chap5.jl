### A Pluto.jl notebook ###
# v0.14.8

using Markdown
using InteractiveUtils

# ╔═╡ 685e660f-1308-4b28-9ebf-9987fa5f1327
begin
	using PlutoUI
end

# ╔═╡ 5d4444bc-de82-11eb-346e-a7e0d69e4e6a
md"""
# Chapter 5
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ ba6eadb4-0fbf-412e-b325-959c7afacfac
md"""
## 5.4
 $N$個の正の整数$a_0, a_1, \dots, a_{N-1}$と正の整数$W$が与えられます. $N$個の整数から$k$個以下の整数を選んで総和を$W$に一致させることができるかどうかを$O(NW)$で判定するアルゴリズムを設計してください.
"""

# ╔═╡ 0d2baa97-401a-4d8a-8507-284a45aa9f7c
md"""
**仮定:**
-  $1 \le k \le N$
"""

# ╔═╡ 42221a73-c542-47ff-9c01-eea5236e819e
function f₄(as, W, k)
	N = length(as)
	dp = falses(N, W)
	nums = zeros(Int, N, W) # Minimum number of as to achieve dp cells
	
	#First row
	if W ≥ as[1]
		dp[1, as[1]] = true
		nums[1, as[1]] = 1
	end
	# Second and later rows
	for n in 2:N, w in 1:W
		if dp[n-1, w]
			dp[n, w] = true
			nums[n, w] = nums[n - 1, w]
		elseif w == as[n]
			dp[n, w] = true
			nums[n, w] = 1
		elseif w > as[n] && dp[n - 1, w - as[n]] && nums[n - 1, w - as[n]] < k
			dp[n, w] = true
			nums[n, w] = nums[n - 1, w - as[n]] + 1
		end
	end
	
	return dp[N, W]
end

# ╔═╡ c5d3896c-a8f8-4490-865d-077aaf2b7c54
with_terminal() do
	as = [2, 4, 8]
	k = 2
	println("Given a = $as, k = $k")
	for W in 1:16
		println("W = $W: $(f₄(as, W, k))")
	end
end

# ╔═╡ df5fc66e-334f-4b78-bd2c-ec85ce5b7cc4
md"""
## 5.5
 $N$個の正の整数$a_0, a_1, \dots, a_{N-1}$と正の整数$W$が与えられます.
$N$個の整数それぞれについて何回足しても良いとした時に総和を$W$に一致させるかどうかを$O(NW)$で判定するアルゴリズムを設計してください.
"""

# ╔═╡ 6cf4cc69-aebf-447f-9041-28bb28bfd084
md"""
**答**
5.6の個数制限が, $i \in \{0, 1, \dots, N-1\}$に対して, $m_i = \lceil W / a_i \rceil$
の場合と一致するため, 省略.
"""

# ╔═╡ 4ebd1018-0cc6-4755-9e40-f51dc9e9407f
md"""
## 5.6
 $N$個の正の整数$a_0, a_1, \dots, a_{N-1}$と正の整数$W$が与えられます.
$N$個の整数それぞれについて$m\_0, m\_1, \dots, m_{N-1}$回まで足しても良いとした時に総和を$W$に一致させるかどうかを$O(NW)$で判定するアルゴリズムを設計してください.
"""

# ╔═╡ 8d3028b4-be25-4946-9281-3ea409ca178a
md"""
**仮定:**
-  $1 \le m_n $ for $n = 0, 1, \dots, N-1$
"""

# ╔═╡ 7e3f714e-7250-4ff5-a815-86da6cddefa6
function f₆(as, ms, W)
	N = length(as)
	dp = falses(N, W)
	nums = zeros(Int, N, W) # Minimum number of aₙ to achieve dp cells
	
	# First row
	if W ≥ as[1]
		for i in 1:min(ms[1], (W ÷ as[1]))
			dp[1, as[1] * i] = true
			nums[1, as[1] * i] = 1
		end
	end
	
	# Second and later rows
	for n in 2:N, w in 1:W
		if dp[n-1, w]
			dp[n, w] = true
		elseif w == as[n]
			dp[n, w] = true
			nums[n, w] = 1
		elseif w > as[n] && dp[n - 1, w - as[n]]
			dp[n, w] = true
			nums[n, w] = 1
		elseif w > as[n] && dp[n, w - as[n]] && nums[n, w - as[n]] < ms[n]
			dp[n, w] = true
			nums[n, w] = nums[n, w - as[n]] + 1
		end
	end
	
	
	return dp[N, W]
end

# ╔═╡ 18efecbe-5dc0-407e-913e-b23b7d24f419
with_terminal() do
	as = [2, 3, 5]
	ms = [2, 1, 2]
	println("Given a = $as, m = $ms")
	for W in 10:20
		println("W = $W: $(f₆(as, ms, W))")
	end
end

# ╔═╡ Cell order:
# ╟─5d4444bc-de82-11eb-346e-a7e0d69e4e6a
# ╟─685e660f-1308-4b28-9ebf-9987fa5f1327
# ╟─ba6eadb4-0fbf-412e-b325-959c7afacfac
# ╟─0d2baa97-401a-4d8a-8507-284a45aa9f7c
# ╠═42221a73-c542-47ff-9c01-eea5236e819e
# ╟─c5d3896c-a8f8-4490-865d-077aaf2b7c54
# ╟─df5fc66e-334f-4b78-bd2c-ec85ce5b7cc4
# ╟─6cf4cc69-aebf-447f-9041-28bb28bfd084
# ╟─4ebd1018-0cc6-4755-9e40-f51dc9e9407f
# ╟─8d3028b4-be25-4946-9281-3ea409ca178a
# ╠═7e3f714e-7250-4ff5-a815-86da6cddefa6
# ╟─18efecbe-5dc0-407e-913e-b23b7d24f419
