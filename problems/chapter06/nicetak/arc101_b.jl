using DataStructures

function check(x, as)
    N = length(as)
    tmps = [(a < x) ? -1 : 1 for a in as]
    ss = vcat(0, cumsum(tmps))
    ps = sortperm(ss)
    bs = FenwickTree{Int}(length(ps))

    q_inv = 0
    for p in ps
        q_inv += prefixsum(bs, p)
        inc!(bs, p, 1)
    end

    return 2q_inv ≥ N * (N +1) ÷ 2
end

function main()
    N = parse(Int, readline())
    as = parse.(Int, split(readline()))

    x̲, x̄ = minimum(as), maximum(as)
    while x̄ - x̲ > 1
        x = (x̲ + x̄) ÷ 2
        
        if check(x, as)
            x̲ = x
        else
            x̄ = x
        end
    end
    
    if check(x̄, as)
        println(x̄)
    else
        println(x̲)
    end

end

main()
