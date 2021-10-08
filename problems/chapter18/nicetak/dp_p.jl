function rec(G, dp1, dp2, v, p = -1)
    MOD = 10^9 + 7

    for v′ ∈ G[v]
        v′ != p && rec(G, dp1, dp2, v′, v)
    end
    
    for v′ ∈ G[v]
        if v′ != p
            dp1[v] = dp1[v] * (dp1[v′] + dp2[v′]) % MOD
            dp2[v] = dp2[v] * dp1[v′] % MOD
        end
    end
    
end


function main()
    MOD = 10^9 + 7
    N = parse(Int, readline())
    G = [Vector{Int}() for _ in 1:N]
    
    for _ = 1:N-1
        x, y = parse.(Int, split(readline()))
        push!(G[x], y)
        push!(G[y], x)
    end

    dp1 = ones(Int, N)
    dp2 = ones(Int, N)
    rec(G, dp1, dp2, 1)

    println((dp1[1] + dp2[1]) % MOD)
end

main()