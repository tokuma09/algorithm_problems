using DataStructures

function tp_sort(G)
	n = length(G)
	
	# Create Reversed Graph G′
	G′ = [Vector{Int}() for _ in 1:n]
	for i = 1:n, e ∈ G[i]
		push!(G′[e], i)
	end
	
	num_ins = [length(g) for g ∈ G]
	
	que = Queue{Int}()
	for i = 1:n
		num_ins[i] == 0 && enqueue!(que, i)
	end
	
	ans = MutableLinkedList{Int}()
	while !isempty(que)
		now = dequeue!(que)
		pushfirst!(ans, now)
		for e ∈ G′[now]
			num_ins[e] -= 1
			num_ins[e] == 0 && enqueue!(que, e)
		end
	end
	
	return collect(ans)
end

function main()
    N, M = parse.(Int, split(readline()))
    
    G = [Vector{Int}() for _ in 1:N]
	for _ in 1:M
		src, dst = parse.(Int, split(readline()))
		push!(G[src], dst)
	end

    dp = zeros(Int, N) #dp[i] := the length of the longest path if i is the last node.
    tps = tp_sort(G)
    for v ∈ tps, v′ ∈ G[v]
        dp[v′] = max(dp[v′], dp[v] + 1)
    end

    println(maximum(dp))
end

main()