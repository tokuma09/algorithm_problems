function main()
    s, t = readline(), readline()
    lₛ, lₜ = length(s), length(t)

    dp = zeros(Int, lₛ+1, lₜ+1)

    for i in 2:(lₛ+1), j in 2:(lₜ+1)
        dp[i, j] = max(dp[i-1, j], dp[i, j-1], dp[i-1, j-1] + (s[i-1]==t[j-1]))
    end

    ans = ""
    i, j = lₛ+1, lₜ+1
    while i ≥ 2 && j ≥ 2
        if s[i-1] == t[j-1]
            ans = "$(s[i-1])$ans"
            i -= 1
            j -= 1
        elseif dp[i, j-1] > dp[i-1, j]
            j -= 1
        else
            i -= 1
        end
    end


    println(ans)
end

main()