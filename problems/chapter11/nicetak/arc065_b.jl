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

function main()
    N, K, L = parse.(Int, split(readline()))

    uf₁ = UnionFind(N)
    uf₂ = UnionFind(N)

    for _ in 1:K
        p, q = parse.(Int, split(readline()))
        unite!(uf₁, p, q)
    end

    for _ in 1:L
        r, s = parse.(Int, split(readline()))
        unite!(uf₂, r, s)
    end

    d = Dict{Tuple{Int, Int}, Int}()
    for i in 1:N
        key = (root!(uf₁, i), root!(uf₂, i)) 
        if haskey(d, key)
            d[key] += 1
        else
            d[key] = 1
        end
    end

    for i in 1:N-1
        print(d[(root!(uf₁, i), root!(uf₂, i))], " ")
    end
    
    println(d[(root!(uf₁, N), root!(uf₂, N))])
end

main()