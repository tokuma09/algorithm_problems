function f753(N::Int, K = 0, n₃ = 0, n₅ = 0, n₇ = 0)
    if K > N
        return 0
    else
        result = (n₃ > 0 && n₅ > 0 && n₇ > 0) +
            f753(N, 10K + 3, n₃ + 1, n₅, n₇) + 
            f753(N, 10K + 5, n₃, n₅ + 1, n₇) + 
            f753(N, 10K + 7, n₃, n₅, n₇ + 1)
        return result
    end
end

function main()
    N = parse(Int, readline())
    println(f753(N))
end

main()
