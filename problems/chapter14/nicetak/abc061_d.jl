mutable struct Edge
    to::Int
    w::Float64
end

function main()
    N, M = parse.(Int, split(readline()))
    G = [Vector{Edge}() for _ = 1:N]
    for _ = 1:M
        a, b, c = parse.(Int, split(readline()))
        push!(G[a], Edge(b, -c))
    end

    # Bellman-Ford
    has_negative_cycle = false
    dists = fill(Inf, N)
    dists[1] = 0.0
    for i = 1:N
        for v = 1:N
            if !isinf(dists[v])
                for e ∈ G[v]
                    if dists[e.to] > dists[v] + e.w
                        dists[e.to] = dists[v] + e.w
                        if e.to == N && i == N 
                            has_negative_cycle = true
                        end
                    end
                end
            end
        end
        
    end

    if has_negative_cycle
        println("inf")
    else
        println("$(-floor(Int, dists[end]))")
    end
end

main()