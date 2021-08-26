function dp(M, i, p, memo)
    # Base case
    if i == 1
        return M[i][p]
    end

    #Memorized
    if memo[i, p] > 0
        return memo[i, p]
    end
    
    # Recursion
    if p == 1
        return memo[i, p] = M[i][p] + max(dp(M, i-1, 2, memo), dp(M, i-1, 3, memo))
    elseif p == 2
        return memo[i, p] = M[i][p] + max(dp(M, i-1, 1, memo), dp(M, i-1, 3, memo))
    elseif p == 3
        return memo[i, p] = M[i][p] + max(dp(M, i-1, 1, memo), dp(M, i-1, 2, memo))
    end
end

function main()
    N = parse(Int, readline())
    M = [parse.(Int, split(readline())) for _ in 1:N]
    memo = zeros(Int, N, 3)

    println(max(dp(M, N, 1, memo), dp(M, N, 2, memo), dp(M, N, 3, memo)))
end

main()