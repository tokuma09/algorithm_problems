function main()
    N, K = parse.(Int, split(readline()))
    as = parse.(Int, split(readline()))
    bs = parse.(Int, split(readline()))

    sort!(bs)
    
    l, r = 0, maximum(as) * bs[end]
    while r - l > 1
        m = (l + r) ÷ 2
        cnt = 0
        for a in as
            cnt += searchsortedlast(bs, m ÷ a)
        end

        if cnt ≥ K
            r = m
        else
            l = m
        end
    end

    println(r)
end

main()