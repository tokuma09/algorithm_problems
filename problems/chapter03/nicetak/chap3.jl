### A Pluto.jl notebook ###
# v0.14.8

using Markdown
using InteractiveUtils

# ╔═╡ 79168b5e-0805-4413-848a-8c501d81d91c
md"""
## 3.2
 $N$個の整数$a_0, a_1, \dots, a_{N-1}$のうち, 整数値$v$が何個含まれるかを求める$O(N)$のアルゴリズムを設計してください.
"""

# ╔═╡ e76f50bc-5cd6-481f-8fe8-b523534c1e11
function f₂(as, v)
	cnt = 0
	for a ∈ as
		if a == v
			cnt += 1
		end
	end
	return cnt
end

# ╔═╡ add92227-31f6-4408-a527-8f46f586c531
f₂([1 2 3 4 5 3], 3)

# ╔═╡ db1a3c61-5a3d-4431-b3e1-786415736801
f₂([1 2 3 4 5 3], 100)

# ╔═╡ 4349dc9c-cfcc-472e-b611-f87f22c9d4ee
md"""
## 3.3
 $N(\ge 2)$個の相異なる整数$a_0, a_1, \dots, a_{N-1}$が与えられます. このうち2番目に小さい値を求める$O(N)$のアルゴリズムを設計してください.
"""

# ╔═╡ 01f68ae8-e149-44dd-bf11-44e428f29500
function f₃(as)
	max₁, max₂ = maximum(as[1:2]), minimum(as[1:2])
	for a ∈ as
		if a > max₁
			max₂ = max₁
			max₁ = a
		elseif max₁ > a > max₂
			max₂ = a
		end
	end
	
	return max₂
end

# ╔═╡ b82ccb0e-c956-4e57-9470-7bd5ef4df4b3
f₃([1 2 3 4 5 6])

# ╔═╡ 8df5aae2-5299-40b0-a0db-ac83badd21b1
f₃([1 100 3 4 105 6])

# ╔═╡ f8afba4c-cf89-11eb-0c82-0fe26b9b6ff9
md"""
## 3.4
 $N$個の整数$a_0, a_1, \dots, a_{N-1}$が与えられます. この中から2つ選んで差をとります. その差の最大値を求める$O(N)$のアルゴリズムを設計してください.
"""

# ╔═╡ 6abeb865-69a0-43c9-bff3-03b17d2d6dfe
f₄(as) = maximum(as) - minimum(as)

# ╔═╡ 72bb5735-f769-4043-9305-41dd590f95e5
f₄([1 2 3 4 5 6])

# ╔═╡ f1b037f4-be79-4563-9e5f-97e2a3105d63
f₄([1 100 3 4 105 6])

# ╔═╡ Cell order:
# ╟─79168b5e-0805-4413-848a-8c501d81d91c
# ╠═e76f50bc-5cd6-481f-8fe8-b523534c1e11
# ╠═add92227-31f6-4408-a527-8f46f586c531
# ╠═db1a3c61-5a3d-4431-b3e1-786415736801
# ╟─4349dc9c-cfcc-472e-b611-f87f22c9d4ee
# ╠═01f68ae8-e149-44dd-bf11-44e428f29500
# ╠═b82ccb0e-c956-4e57-9470-7bd5ef4df4b3
# ╠═8df5aae2-5299-40b0-a0db-ac83badd21b1
# ╟─f8afba4c-cf89-11eb-0c82-0fe26b9b6ff9
# ╠═6abeb865-69a0-43c9-bff3-03b17d2d6dfe
# ╠═72bb5735-f769-4043-9305-41dd590f95e5
# ╠═f1b037f4-be79-4563-9e5f-97e2a3105d63
