function main()
    N = parse(Int, readline())
    reds = [parse.(Int, split(readline())) for _ in 1:N]
    blues = [parse.(Int, split(readline())) for _ in 1:N]
    
    sort!(reds, rev=true, by = x -> x[2])
    sort!(blues, by = x -> x[1])

    ans = 0
    ismatched_reds = falses(N)
    for b in blues
        for (i, r) in enumerate(reds)
            if !ismatched_reds[i] && r[1] < b[1] && r[2] < b[2]
                ismatched_reds[i] = true
                ans += 1
                break
            end
        end
    end
    
    println(ans)
end

main()