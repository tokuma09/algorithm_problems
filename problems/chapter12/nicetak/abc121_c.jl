function main()
    N, M = parse.(Int, split(readline()))
    AB = [parse.(Int, split(readline())) for _ in 1:N]

    sort!(AB)
    ans = 0
    for i in 1:N
        A, B = AB[i][1], AB[i][2]
        if M ≤ B
            ans += A * M
            break
        else
            ans += A * B
            M -= B
        end
    end

    println(ans)
end

main()