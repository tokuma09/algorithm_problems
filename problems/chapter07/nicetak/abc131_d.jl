function main()
    N = parse(Int, readline())
    AB = [parse.(Int, split(readline())) for _ in 1:N]
    AB_s = sort(AB, by = x -> x[2])
    
    ans = "Yes"
    tmp = 0
    for ab in AB_s
        tmp += ab[1]
        if tmp > ab[2]
            ans = "No"
            break
        end
    end
    
    println(ans)
end

main()