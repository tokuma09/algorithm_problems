struct UnionFind
    par::Vector{Int}
    size::Vector{Int}
    UnionFind(n) = new(collect(1:n), ones(Int, n))
end
 
root!(uf, x) = uf.par[x] == x ? x : uf.par[x] = root!(uf, uf.par[x])
 
same(uf, x, y) = root!(uf, x) == root!(uf, y)        
 
function unite!(uf, x, y)
    x = root!(uf, x)
    y = root!(uf, y)
    x == y && return false
 
    if uf.size[x] > uf.size[y]
        uf.par[y] = x
        uf.size[x] += uf.size[y]
    else
        uf.par[x] = y
        uf.size[y] += uf.size[x]
    end
    return true
end
size!(uf, x) = uf.size[root!(uf, x)]


struct Edge
    s::Int
    t::Int
    c::Int
end

import Base: isless
isless(e₁::Edge, e₂::Edge) = isless(e₁.c, e₂.c) # For sorting

function solve(n, m)
    edges = [Edge((parse.(Int, split(readline())))...) for _ = 1:m]

    sort!(edges)
    uf = UnionFind(n)
    cnt_edges = 0
    ans = 0
    for e ∈ edges
        if !same(uf, e.s, e.t)
            unite!(uf, e.s, e.t)
            cnt_edges += 1
        end

        if cnt_edges == (n + 1) ÷ 2
            ans = e.c
            break
        end
    end

    println(ans)
end

function main()
    while true
        n, m = parse.(Int, split(readline()))
        if n == 0 && m == 0
            break
        else
            solve(n, m)
        end
    end
end

main()