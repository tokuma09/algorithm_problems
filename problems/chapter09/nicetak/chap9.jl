### A Pluto.jl notebook ###
# v0.15.1

using Markdown
using InteractiveUtils

# ╔═╡ ee0915fd-eacc-47ef-8ada-fd83909bae18
begin
	using PlutoUI
	using DataStructures
end

# ╔═╡ aa81ee70-e559-11eb-17be-9b561a8ae8db
md"""
# Chapter 9
#### Nicetak
 $(import Dates; Dates.format(Dates.today(), Dates.DateFormat("U d, Y")))
"""

# ╔═╡ d975985b-84e7-4d2c-968e-eb2f7bcff5c2
md"""
### 9.1
連結リストを用いてスタックとキューを実現してください.
"""

# ╔═╡ 585e300b-0844-4867-a252-b58fff71b63a
begin
	mutable struct MyStack{T}
		l::MutableLinkedList{T}
		
		function MyStack{T}() where T
			mst = new{T}()
			mst.l = MutableLinkedList{T}()
			
			return mst
		end
	end
	
	MyStack() = MyStack{Any}()
	
	function Base.push!(mst::MyStack, x)
		push!(mst.l, x)
		return mst
	end
	
	function Base.pop!(mst::MyStack)
		pop!(mst.l)
		return mst
	end
	
	function Base.show(io::IO, mst::MyStack)
    	print(io, typeof(mst), '(')
	    join(io, mst.l, ", ")
    	print(io, ')')
	end
end

# ╔═╡ be538624-5d9c-4849-ba32-2e0055764805
begin
	mutable struct MyQueue{T}
		l::MutableLinkedList{T}
		
		function MyQueue{T}() where T
			mq = new{T}()
			mq.l = MutableLinkedList{T}()
			
			return mq
		end
	end
	
	MyQueue() = MyQueue{Any}()
	
	function DataStructures.enqueue!(mq::MyQueue, x)
		push!(mq.l, x)
		return mq
	end
	
	function DataStructures.dequeue!(mq::MyQueue)
		popfirst!(mq.l)
		return mq
	end
	
	function Base.show(io::IO, mq::MyQueue)
    	print(io, typeof(mq), '(')
	    join(io, mq.l, ", ")
    	print(io, ')')
	end
end

# ╔═╡ 88bfe770-9756-4c79-be16-67c92798d700
with_terminal() do
	@show mst = MyStack{Int}()
	
	@show push!(mst, 3)
	@show push!(mst, 5)
	@show push!(mst, 7)
	
	@show pop!(mst)
	@show pop!(mst)
	
	@show push!(mst, 9)
	
end

# ╔═╡ ad3ad687-f324-42d3-b3ab-c1264cf1137d
with_terminal() do
	@show mq = MyQueue{Int}()
	
	@show enqueue!(mq, 3)
	@show enqueue!(mq, 5)
	@show enqueue!(mq, 7)
	
	@show dequeue!(mq)
	@show dequeue!(mq)
	
	@show enqueue!(mq, 9)
	
end

# ╔═╡ c54762ef-f758-470e-9329-7943e73f1057
md"""
## 9.2
逆ポーランド記法で記述された数式を入力として受け取って, その計算結果を出力するアルゴリズムを設計してください.
"""

# ╔═╡ c37576ea-fdab-49ae-8967-f525ca26cb0f
function rpn(s::String)
	st = Stack{Any}()
	for e in eval.(Meta.parse.(split(s)))
		if isa(e, Function)
			arg2 = pop!(st)
			arg1 = pop!(st)
			push!(st, e(arg1, arg2))
		else
			push!(st, e)
		end
	end
	
	return pop!(st)
end

# ╔═╡ f2be00f6-b8eb-4337-a83a-e73ce805bfdf
with_terminal() do
	ss = [
		"1 2 + 3 4 + +",
		"3 4 * 1 * 2 -",
		"2 3 * 1 4 * +"
	]
	for s in ss
		println("\"$s\" = $(rpn(s))")
	end
end

# ╔═╡ e507c176-96e0-48b0-9772-ac72519f1be0
md"""
### 9.3
"(()(())())(()())"のような'('と')'からなる, 長さ$2N$の文字列が与えられます. この文字列において括弧列が整合しているかどうかを判定し, さらに何文字目と何文字目の括弧が対応しているかを$N$組求める処理を,
$O(N)$で実行するアルゴリズムを設計してください.
"""

# ╔═╡ b7ce3689-afe5-4854-a4dd-7d937bab4fdc
function parenthesis(s::String)
	N = length(s) ÷ 2
	
	st = Stack{Int}()
	ans = zeros(Int, N, 2)
	idx = 1
	
	for i in eachindex(s)
		if s[i] == '('
			push!(st, i)
		else
			if isempty(st)
				return println("invalid")
			else
				j = pop!(st)
				ans[idx, :] = [j i]
				idx += 1
			end
		end
	end
	
	if isempty(st)
		println(ans)
	else
		println("invalid")
	end
end

# ╔═╡ e3c9bb00-6bc4-44f7-9744-6505f2a2797b
with_terminal() do
	ss = ["(((())())())", "(()", "())"]
	for s ∈ ss
		print("\"$s\" → ")
		parenthesis(s)
	end
end

# ╔═╡ 00000000-0000-0000-0000-000000000001
PLUTO_PROJECT_TOML_CONTENTS = """
[deps]
DataStructures = "864edb3b-99cc-5e75-8d2d-829cb0a9cfe8"
PlutoUI = "7f904dfe-b85e-4ff6-b463-dae2292396a8"

[compat]
DataStructures = "~0.18.10"
PlutoUI = "~0.7.9"
"""

# ╔═╡ 00000000-0000-0000-0000-000000000002
PLUTO_MANIFEST_TOML_CONTENTS = """
# This file is machine-generated - editing it directly is not advised

[[ArgTools]]
uuid = "0dad84c5-d112-42e6-8d28-ef12dabb789f"

[[Artifacts]]
uuid = "56f22d72-fd6d-98f1-02f0-08ddc0907c33"

[[Base64]]
uuid = "2a0f44e3-6c83-55bd-87e4-b1978d98bd5f"

[[Compat]]
deps = ["Base64", "Dates", "DelimitedFiles", "Distributed", "InteractiveUtils", "LibGit2", "Libdl", "LinearAlgebra", "Markdown", "Mmap", "Pkg", "Printf", "REPL", "Random", "SHA", "Serialization", "SharedArrays", "Sockets", "SparseArrays", "Statistics", "Test", "UUIDs", "Unicode"]
git-tree-sha1 = "727e463cfebd0c7b999bbf3e9e7e16f254b94193"
uuid = "34da2185-b29b-5c13-b0c7-acf172513d20"
version = "3.34.0"

[[DataStructures]]
deps = ["Compat", "InteractiveUtils", "OrderedCollections"]
git-tree-sha1 = "7d9d316f04214f7efdbb6398d545446e246eff02"
uuid = "864edb3b-99cc-5e75-8d2d-829cb0a9cfe8"
version = "0.18.10"

[[Dates]]
deps = ["Printf"]
uuid = "ade2ca70-3891-5945-98fb-dc099432e06a"

[[DelimitedFiles]]
deps = ["Mmap"]
uuid = "8bb1440f-4735-579b-a4ab-409b98df4dab"

[[Distributed]]
deps = ["Random", "Serialization", "Sockets"]
uuid = "8ba89e20-285c-5b6f-9357-94700520ee1b"

[[Downloads]]
deps = ["ArgTools", "LibCURL", "NetworkOptions"]
uuid = "f43a241f-c20a-4ad4-852c-f6b1247861c6"

[[InteractiveUtils]]
deps = ["Markdown"]
uuid = "b77e0a4c-d291-57a0-90e8-8db25a27a240"

[[JSON]]
deps = ["Dates", "Mmap", "Parsers", "Unicode"]
git-tree-sha1 = "8076680b162ada2a031f707ac7b4953e30667a37"
uuid = "682c06a0-de6a-54ab-a142-c8b1cf79cde6"
version = "0.21.2"

[[LibCURL]]
deps = ["LibCURL_jll", "MozillaCACerts_jll"]
uuid = "b27032c2-a3e7-50c8-80cd-2d36dbcbfd21"

[[LibCURL_jll]]
deps = ["Artifacts", "LibSSH2_jll", "Libdl", "MbedTLS_jll", "Zlib_jll", "nghttp2_jll"]
uuid = "deac9b47-8bc7-5906-a0fe-35ac56dc84c0"

[[LibGit2]]
deps = ["Base64", "NetworkOptions", "Printf", "SHA"]
uuid = "76f85450-5226-5b5a-8eaa-529ad045b433"

[[LibSSH2_jll]]
deps = ["Artifacts", "Libdl", "MbedTLS_jll"]
uuid = "29816b5a-b9ab-546f-933c-edad1886dfa8"

[[Libdl]]
uuid = "8f399da3-3557-5675-b5ff-fb832c97cbdb"

[[LinearAlgebra]]
deps = ["Libdl"]
uuid = "37e2e46d-f89d-539d-b4ee-838fcccc9c8e"

[[Logging]]
uuid = "56ddb016-857b-54e1-b83d-db4d58db5568"

[[Markdown]]
deps = ["Base64"]
uuid = "d6f4376e-aef5-505a-96c1-9c027394607a"

[[MbedTLS_jll]]
deps = ["Artifacts", "Libdl"]
uuid = "c8ffd9c3-330d-5841-b78e-0817d7145fa1"

[[Mmap]]
uuid = "a63ad114-7e13-5084-954f-fe012c677804"

[[MozillaCACerts_jll]]
uuid = "14a3606d-f60d-562e-9121-12d972cd8159"

[[NetworkOptions]]
uuid = "ca575930-c2e3-43a9-ace4-1e988b2c1908"

[[OrderedCollections]]
git-tree-sha1 = "85f8e6578bf1f9ee0d11e7bb1b1456435479d47c"
uuid = "bac558e1-5e72-5ebc-8fee-abe8a469f55d"
version = "1.4.1"

[[Parsers]]
deps = ["Dates"]
git-tree-sha1 = "438d35d2d95ae2c5e8780b330592b6de8494e779"
uuid = "69de0a69-1ddd-5017-9359-2bf0b02dc9f0"
version = "2.0.3"

[[Pkg]]
deps = ["Artifacts", "Dates", "Downloads", "LibGit2", "Libdl", "Logging", "Markdown", "Printf", "REPL", "Random", "SHA", "Serialization", "TOML", "Tar", "UUIDs", "p7zip_jll"]
uuid = "44cfe95a-1eb2-52ea-b672-e2afdf69b78f"

[[PlutoUI]]
deps = ["Base64", "Dates", "InteractiveUtils", "JSON", "Logging", "Markdown", "Random", "Reexport", "Suppressor"]
git-tree-sha1 = "44e225d5837e2a2345e69a1d1e01ac2443ff9fcb"
uuid = "7f904dfe-b85e-4ff6-b463-dae2292396a8"
version = "0.7.9"

[[Printf]]
deps = ["Unicode"]
uuid = "de0858da-6303-5e67-8744-51eddeeeb8d7"

[[REPL]]
deps = ["InteractiveUtils", "Markdown", "Sockets", "Unicode"]
uuid = "3fa0cd96-eef1-5676-8a61-b3b8758bbffb"

[[Random]]
deps = ["Serialization"]
uuid = "9a3f8284-a2c9-5f02-9a11-845980a1fd5c"

[[Reexport]]
git-tree-sha1 = "45e428421666073eab6f2da5c9d310d99bb12f9b"
uuid = "189a3867-3050-52da-a836-e630ba90ab69"
version = "1.2.2"

[[SHA]]
uuid = "ea8e919c-243c-51af-8825-aaa63cd721ce"

[[Serialization]]
uuid = "9e88b42a-f829-5b0c-bbe9-9e923198166b"

[[SharedArrays]]
deps = ["Distributed", "Mmap", "Random", "Serialization"]
uuid = "1a1011a3-84de-559e-8e89-a11a2f7dc383"

[[Sockets]]
uuid = "6462fe0b-24de-5631-8697-dd941f90decc"

[[SparseArrays]]
deps = ["LinearAlgebra", "Random"]
uuid = "2f01184e-e22b-5df5-ae63-d93ebab69eaf"

[[Statistics]]
deps = ["LinearAlgebra", "SparseArrays"]
uuid = "10745b16-79ce-11e8-11f9-7d13ad32a3b2"

[[Suppressor]]
git-tree-sha1 = "a819d77f31f83e5792a76081eee1ea6342ab8787"
uuid = "fd094767-a336-5f1f-9728-57cf17d0bbfb"
version = "0.2.0"

[[TOML]]
deps = ["Dates"]
uuid = "fa267f1f-6049-4f14-aa54-33bafae1ed76"

[[Tar]]
deps = ["ArgTools", "SHA"]
uuid = "a4e569a6-e804-4fa4-b0f3-eef7a1d5b13e"

[[Test]]
deps = ["InteractiveUtils", "Logging", "Random", "Serialization"]
uuid = "8dfed614-e22c-5e08-85e1-65c5234f0b40"

[[UUIDs]]
deps = ["Random", "SHA"]
uuid = "cf7118a7-6976-5b1a-9a39-7adc72f591a4"

[[Unicode]]
uuid = "4ec0a83e-493e-50e2-b9ac-8f72acf5a8f5"

[[Zlib_jll]]
deps = ["Libdl"]
uuid = "83775a58-1f1d-513f-b197-d71354ab007a"

[[nghttp2_jll]]
deps = ["Artifacts", "Libdl"]
uuid = "8e850ede-7688-5339-a07c-302acd2aaf8d"

[[p7zip_jll]]
deps = ["Artifacts", "Libdl"]
uuid = "3f19e933-33d8-53b3-aaab-bd5110c3b7a0"
"""

# ╔═╡ Cell order:
# ╟─aa81ee70-e559-11eb-17be-9b561a8ae8db
# ╠═ee0915fd-eacc-47ef-8ada-fd83909bae18
# ╟─d975985b-84e7-4d2c-968e-eb2f7bcff5c2
# ╠═585e300b-0844-4867-a252-b58fff71b63a
# ╠═be538624-5d9c-4849-ba32-2e0055764805
# ╟─88bfe770-9756-4c79-be16-67c92798d700
# ╟─ad3ad687-f324-42d3-b3ab-c1264cf1137d
# ╟─c54762ef-f758-470e-9329-7943e73f1057
# ╠═c37576ea-fdab-49ae-8967-f525ca26cb0f
# ╟─f2be00f6-b8eb-4337-a83a-e73ce805bfdf
# ╟─e507c176-96e0-48b0-9772-ac72519f1be0
# ╠═b7ce3689-afe5-4854-a4dd-7d937bab4fdc
# ╟─e3c9bb00-6bc4-44f7-9744-6505f2a2797b
# ╟─00000000-0000-0000-0000-000000000001
# ╟─00000000-0000-0000-0000-000000000002
