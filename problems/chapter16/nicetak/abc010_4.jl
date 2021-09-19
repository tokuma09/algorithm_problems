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
    N, G, E = parse.(Int, split(readline()))
    ps = parse.(Int, split(readline())) .+ 1

    H = [Vector{Edge}() for _ = 1:N+1] # Count the super node
    for _ = 1:E
        a, b = parse.(Int, split(readline())) .+ 1
        push!(H, a, b, 1)
        push!(H, b, a, 1)
    end

    for p in ps
        push!(H, p, N+1, 1)
        push!(H, N+1, p, 1)
    end

    println(FordFulkerson(H, 1, N+1))
end

main()
