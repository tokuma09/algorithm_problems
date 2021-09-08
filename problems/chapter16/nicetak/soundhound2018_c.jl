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
    r, c = parse.(Int, split(readline()))
    ss = [readline() for _ = 1:r]
    N = r * c
    V = N
    G = [Vector{Edge}() for _ = 1:N+2] # 2 super nodes
    for i = 1:r, j = 1:c
        left = (i - 1) * c + j
        s = ss[i][j]
        if s == '*'
            V -= 1
        else
            if (i + j) % 2 == 0
                for (dx, dy) ∈ zip([0, 1, 0, -1], [1, 0, -1, 0]) 
                    i′ = i + dy
                    j′ = j + dx
                    
                    if 1 ≤ i′ ≤ r && 1 ≤ j′ ≤ c && ss[i′][j′] == '.'
                        right = (i′ - 1) * c + j′
                        push!(G, left, right, 1)
                    end
                end
                push!(G, N+1, left, 1)
            else
                push!(G, left, N+2, 1)
            end
        end
    end

    println(V - FordFulkerson(G, N+1, N+2))
end

main()
