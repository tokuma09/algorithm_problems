using Primes

function solve(A, M)
    L = 50 # ≥ log₂ M 
    if M == 1
        return L 
    end

    φₘ = totient(M)
    x = solve(A, φₘ)
    l = lcm(φₘ, M)
    res = powermod(A, x, l)

    while res < L
        res += l
    end

    return res
end

function main()
    Q = parse(Int, readline())

    for _ in 1:Q
        A, M = parse.(Int, split(readline()))
        println(solve(A, M))
    end
end

main()
