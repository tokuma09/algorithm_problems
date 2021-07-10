function check(d, M, as)
    # as is sorted
    # check if all the cows can have a distance longer than d
    N = length(as)

    last = 1
    for i in 1:(M-1)
        crt = last + 1
        while crt ≤ N && as[crt] - as[last] < d
            crt += 1
        end

        if crt ≥ N
            return false
        else
            last = crt
        end
    end

    return true
end

function main()
    N, M = parse.(Int, split(readline()))
    as = [parse(Int, readline()) for _ in 1:N]
    sort!(as)
    
    d̲, d̄ = 0, maximum(as)
    while d̄ - d̲ > 1
        d = (d̄ + d̲) ÷ 2
        if check(d, M, as)
            d̲ = d
        else
            d̄ = d
        end
    end

    if check(d̄, M, as)
        println(d̄)
    else
        println(d̲)
    end
end

main()