mutable struct Edge
    rev::Int
    from::Int
    to::Int
    cap::Int
end

function push!(G::Vector{Vector{Edge}}, from, to, cap)
    fromrev = length(G[from]) + 1
    torev = length(G[to]) + 1
    Base.push!(G[from], Edge(torev, from, to, cap))
    Base.push!(G[to], Edge(fromrev, to, from, 0))
end

function run_flow!(G::Vector{Vector{Edge}}, e::Edge, f)
    e.cap -= f
    G[e.to][e.rev].cap += f
    return G
end

function fodfs(G, v, t, f, seens)
    v == t && return f

    seens[v] = true
    for e ∈ G[v]
        if seens[e.to] || e.cap == 0
            # Skip
        else
            flow = fodfs(G, e.to, t, min(f, e.cap), seens)
            if flow == 0
                # Skip
            else
                run_flow!(G, e, flow)
                return flow
            end
        end
    end

    return 0
end

function FordFulkerson(G, s, t)
    INF = 10^9
    res = 0

    while true
        flow = fodfs(G, s, t, INF, falses(length(G)))
        if flow == 0
            return res
        else
            res += flow
        end
    end

    return 0
end


function main()
    N = parse(Int, readline())
    as = parse.(Int, split(readline()))
    INF = 10^9

    offset = 0
    G = [Vector{Edge}() for _ = 1:N+2]
    for (i, a) = enumerate(as)
        if a ≥ 0
            push!(G, N+1, i, 0)
            push!(G, i, N+2, a)
            offset += a
        else
            push!(G, N+1, i, -a)
            push!(G, i, N+2, 0)
        end
    end

    for i = 1:N
        for j = i+1:N
            if j % i == 0
                push!(G, i, j, INF)
            end
        end
    end

    res = FordFulkerson(G, N+1, N+2)
    println(offset - res)
end

main()