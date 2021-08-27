using DataStructures

function main()
    N, M = parse.(Int, split(readline()))
    G = [Vector{Int}() for _ = 1:N]
    for _ = 1:M
        u, v = parse.(Int, split(readline()))
        push!(G[u], v)
    end
    S, T = parse.(Int, split(readline()))

    # Solve
    dists = -ones(Int, N, 3)
    dists[S, 1] = 0
    que = Queue{Tuple{Int, Int}}()
    enqueue!(que, (S, 1))
    while !isempty(que)
        v, s = dequeue!(que)
        for v′ ∈ G[v]
            s′ = s % 3 + 1
            if dists[v′, s′] == -1
                dists[v′, s′] = dists[v, s] + 1
                enqueue!(que, (v′, s′))
            end
        end
    end

    if dists[T, 1] == -1
        println("-1")
    else
        println("$(dists[T, 1] ÷ 3)")
    end
end

main()