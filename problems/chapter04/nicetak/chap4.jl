### A Pluto.jl notebook ###
# v0.14.8

using Markdown
using InteractiveUtils

# ╔═╡ 86a927d5-0b05-4a7a-83c4-0f98fb15509e
begin
	using PlutoUI
	using Plots
end

# ╔═╡ 5d15bae3-d408-4f74-98a3-8b5e53562770
md"""
# Chapter 4
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ 435ece74-d26a-11eb-1bd1-5b65d058f3a1
md"""
## 4.1
トリボナッチ数列の第$N$項の値を求める再起関数を設計してください.
"""

# ╔═╡ 4a01190f-1e0e-4371-9847-e66eeab849b9
function f₁(n)
	if n == 0
		return 0
	elseif n == 1
		return 0
	elseif n == 2
		return 1
	end
	
	return f₁(n - 1) + f₁(n - 2) + f₁(n - 3)
end

# ╔═╡ 0224c51b-3028-45f0-bf6c-7423aac643a6
with_terminal() do
	for n ∈ 0:9
		println("n = $n: $(f₁(n))")
	end
end

# ╔═╡ aa51aa81-b8be-4e65-b259-e816655d01c9
plot(n -> (@timed f₁(n)).time, 1:33,
	title = "Computational Time of Naive Tribonacci",
	xlabel = "n",
	ylabel = "Seconds",
	legend = false
)

# ╔═╡ 5d8bedcf-6f20-4be3-961b-3b81ef486209
md"""
## 4.2
問題4.1で設計した再帰関数をメモ化によって効率化してください.
また, メモ化を実施後の計算量を評価してください.
"""

# ╔═╡ 1f806382-2995-4da2-b33d-c0403c530163
function f₂(n, memo = -ones(Int, n))
	if n == 0
		return 0
	elseif n == 1
		return 0
	elseif n == 2
		return 1
	end
	
	if memo[n] != -1
		return memo[n]
	end
	
	res = f₂(n - 1, memo) + f₂(n - 2, memo) + f₂(n - 3, memo)
	memo[n] = res
	return res
end

# ╔═╡ 645cdd0a-97c5-4a90-a70e-09a3571142db
with_terminal() do
	for n ∈ 0:9
		println("n = $n: $(f₂(n))")
	end
end

# ╔═╡ d65730a4-ec5f-436f-876b-fc98eb203107
md"""
計算量は$T_0, \dots, T_{N-1}$までメモ化されている時, $T_N$の計算量が$O(1)$であることから, $O(N)$.
"""

# ╔═╡ 3ac6e8f6-a3e9-4d81-a271-5457b20477bc
plot(n -> median((@timed f₂(n)).time for _ in 1:100), 1:3000,
	title = "Computational Time of Memorized Tribonacci",
	xlabel = "n",
	ylabel = "Seconds",
	legend = false
)

# ╔═╡ f6e73830-ad09-4718-868d-26f6a2c11b16
md"""
## 4.3
フィボナッチ数列の一般項が
$F_N = \frac{1}{\sqrt{5}}\left[\left(\frac{1 + \sqrt{5}}{2}\right)^N -
\left(\frac{1 - \sqrt{5}}{2}\right)^N \right]$
で表されることを示してください.
"""

# ╔═╡ 65503b27-14d4-42c8-abec-70060988d465
md"""
**答**
$F_0 = 1, F_1 = 1$は自明. 一般項を$F_{N-1}$まで仮定して,

$\begin{aligned}
\sqrt{5}(F_{N-1} + F_{N-2}) &= \left(1 + \frac{2}{1 + \sqrt{5}}\right)
\left(\frac{1 + \sqrt{5}}{2}\right)^{N-1} -
\left(1 + \frac{2}{1 - \sqrt{5}}\right)
\left(\frac{1 - \sqrt{5}}{2}\right)^{N-1} \\
&= \left(\frac{1 + \sqrt{5}}{2}\right)^N -
\left(\frac{1 - \sqrt{5}}{2}\right)^N.
\end{aligned}$
よって,
$F_N = F_{N - 1} + F_{N - 2}$.
帰納法から, 命題は示された.
"""

# ╔═╡ ae54b3e7-e04c-457f-839d-8aeecb6eba0d
md"""
## 4.4
コード 4.5で示したアルゴリズムの計算量が $O\left(\left(\frac{1 + \sqrt{5}}{2}\right)^N\right)$ で与えられることを示してください.
"""

# ╔═╡ e0cd89ce-9a49-4d51-9c36-1b467b3e4add
md"""
**答** コード4.5のアルゴリズムの計算量が$O(f(N))$であると仮定する.
定義から, $f(0) = f(1) = 1$は自明. また, Big Oの計算規則とコードの定義から,

$f(N) = f(N - 1) + f(N - 2).$

これはフィボナッチ数列と一致し, 一般項は問4.3で示された通りである.
支配項は$\left(\frac{1 + \sqrt{5}}{2}\right)^N$であるから, 命題は示された.
"""

# ╔═╡ 0303b656-d949-4365-b884-bf7bbc026a6d
md"""
## 4.6
部分和問題に対する再帰関数を用いる計算量$O(2^N)$のコード4.9に対してメモ化して, $O(NW)$ の計算量で動作するようにしてください.
"""

# ╔═╡ 14bcda24-9431-468a-ac5b-4bf6feb1e8e8
function f₆(as, w, i = length(as), memo = -ones(Int, length(as), w))
	if w < 0
		return false
	elseif w == 0
		return true
	elseif i == 0
		return false
	end
	
	if memo[i, w] == 1
		return true
	elseif memo[i, w] == 0
		return false
	end
		
	if f₆(as, w, i - 1, memo)
		memo[i, w] = 1
		return true
	elseif f₆(as, w - as[i], i - 1, memo)
		memo[i, w] = 1
		return true
	else
		memo[i, w] = 0
		return false
	end
		
end

# ╔═╡ 501824d0-017f-4d05-a477-cd7f4cef1df8
with_terminal() do
	println("Given a = [2, 4, 8]")
	for w ∈ 1:16
		println("w = $w: $(f₆([2, 4, 8], w))")
	end
end

# ╔═╡ Cell order:
# ╟─5d15bae3-d408-4f74-98a3-8b5e53562770
# ╠═86a927d5-0b05-4a7a-83c4-0f98fb15509e
# ╟─435ece74-d26a-11eb-1bd1-5b65d058f3a1
# ╠═4a01190f-1e0e-4371-9847-e66eeab849b9
# ╟─0224c51b-3028-45f0-bf6c-7423aac643a6
# ╟─aa51aa81-b8be-4e65-b259-e816655d01c9
# ╟─5d8bedcf-6f20-4be3-961b-3b81ef486209
# ╠═1f806382-2995-4da2-b33d-c0403c530163
# ╟─645cdd0a-97c5-4a90-a70e-09a3571142db
# ╟─d65730a4-ec5f-436f-876b-fc98eb203107
# ╟─3ac6e8f6-a3e9-4d81-a271-5457b20477bc
# ╟─f6e73830-ad09-4718-868d-26f6a2c11b16
# ╟─65503b27-14d4-42c8-abec-70060988d465
# ╟─ae54b3e7-e04c-457f-839d-8aeecb6eba0d
# ╟─e0cd89ce-9a49-4d51-9c36-1b467b3e4add
# ╟─0303b656-d949-4365-b884-bf7bbc026a6d
# ╠═14bcda24-9431-468a-ac5b-4bf6feb1e8e8
# ╟─501824d0-017f-4d05-a477-cd7f4cef1df8
