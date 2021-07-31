struct WeightedUnionFind
    par::Vector{Int}
    rank::Vector{Int}
    diff_weight::Vector{Number}

    WeightedUnionFind(n) = new(collect(1:n), zeros(Int, n), zeros(Number, n))
end

function root!(wuf::WeightedUnionFind, x::Int)
    if wuf.par[x] == x
        return x
    else
        r = root!(wuf, wuf.par[x])
        wuf.diff_weight[x] += wuf.diff_weight[wuf.par[x]]
        return wuf.par[x] = r
    end
end

function weight(wuf::WeightedUnionFind, x)
    root!(wuf, x) # Calculate weight
    return wuf.diff_weight[x]
end

diff(wuf::WeightedUnionFind, x::Int, y::Int) = weight(wuf, y) - weight(wuf, x)
issame(wuf::WeightedUnionFind, x::Int, y::Int) = root!(wuf, x) == root!(wuf, y)

function union!(wuf, x::Int, y::Int, w::Number)
    w += weight(wuf, x)    
    w -= weight(wuf, y)

    x = root!(wuf, x)
    y = root!(wuf, y)
    x == y && return false
    
    if wuf.rank[x] < wuf.rank[y]
        x, y = y, x
        w = -w
    elseif wuf.rank[x] == wuf.rank[y]
        wuf.rank[x] += 1
    end

    wuf.par[y] = x

    wuf.diff_weight[y] = w

    return true
end


function main()
    N, M = parse.(Int, split(readline()))

    wuf = WeightedUnionFind(N)
    ans = "Yes"
    for _ in 1:M
        L, R, D = parse.(Int, split(readline()))

        if issame(wuf, L, R)
            d = diff(wuf, L, R)
            if diff(wuf, L, R) ≠ D
                ans = "No"
                break
            end
        else
            union!(wuf, L, R, D)
        end
    end

    println(ans)
end

main()