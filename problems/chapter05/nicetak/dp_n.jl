function get_lr(l, r, acc_as)
    if l == 1
        return acc_as[r]
    else
        return acc_as[r] - acc_as[l-1]
    end
end

function dp(l, r, as, acc_as, memo)
    if memo[l, r] > 0
        return memo[l, r]
    elseif l == r
        return memo[l, r] = 0
    else
        res = minimum([dp(l, i, as, acc_as, memo) + 
            dp(i+1, r, as, acc_as, memo) +
            get_lr(l, r, acc_as) for i in l:r-1])
        return memo[l, r] = res
    end
end

function main()
    N = parse(Int, readline())
    as = parse.(Int, split(readline()))
    acc_as = cumsum(as)

    memo = zeros(Int, N, N)
    println(dp(1, N, as, acc_as, memo))
end

main()