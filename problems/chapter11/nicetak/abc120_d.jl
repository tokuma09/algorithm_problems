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
    N, M = parse.(Int, split(readline()))
    AB = [parse.(Int, split(readline())) for _ in 1:M]

    anss = zeros(Int, M)
    uf = UnionFind(N)
    
    for i in M:-1:1
        A, B = AB[i][1], AB[i][2]
        if !same(uf, A, B)
            anss[i] = size!(uf, A) * size!(uf, B)
            unite!(uf, A, B)
        end
    end

    for ans in cumsum(anss)
        println(ans)
    end

end

main()