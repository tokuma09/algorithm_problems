function main()
    K, S = parse.(Int, split(readline()))

    cnt = 0
    for X in 0:K, Y in 0:K
        if S - K ≤ X + Y ≤ S
            cnt += 1
        end
    end

    println(cnt)
end

main()
