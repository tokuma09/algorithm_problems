function main()
    N = parse(Int, readline())
    ps = parse.(Int, split(readline()))

    dp = falses(sum(ps) + 1)
    dp[begin] = true # Score zero
    for p in ps
        dp = dp .| vcat(falses(p), dp[begin:end-p])
    end
    
    println(sum(dp))
end

main()