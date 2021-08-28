using DataStructures

function main()
    K = parse(Int, readline())
    INF = 10^9
    
    dists = INF * ones(Int, K)
    dists[2] = 1
    que = Deque{Int}()
    pushfirst!(que, 1)

    while !isempty(que)
        v = popfirst!(que)

        v′ = 10v % K
        if dists[v′+1] > dists[v+1]
            dists[v′+1] = dists[v+1]
            pushfirst!(que, v′)
        end

        v′ = (v + 1) % K
        if dists[v′+1] > dists[v+1] + 1
            dists[v′+1] = dists[v+1] + 1
            push!(que, v′)
        end
    end

    println(dists[1])
end

main()