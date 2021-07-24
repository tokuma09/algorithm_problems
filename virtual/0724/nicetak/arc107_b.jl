function main()
    N, K = parse.(Int, split(readline()))

    f(N, K) = min(K-1, 2N + 1 - K) * (2 ≤ K ≤ 2N)

    ans = 0
    for x in 2:2N
        ans += f(N, x) * f(N, x - K)
    end

    println(ans)
   
end

main()

