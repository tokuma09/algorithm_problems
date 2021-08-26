### A Pluto.jl notebook ###
# v0.14.8

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
			j = pop!(st)
			ans[idx, :] = [j i]
			idx += 1
		end
	end
	
	println(ans)
end

# ╔═╡ e3c9bb00-6bc4-44f7-9744-6505f2a2797b
with_terminal() do
	s = "(((())())())"
	println("Given $s")
	parenthesis(s)
end

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
