function main()
    S = readline()
    N = length(S)

    cnt = 0
    for i = 1:N, j = i:N
        space_left = max(0, i - 2)
        space_right = max(0, N - j - 1)
        cnt += parse(Int, S[i:j]) * 2^(space_left + space_right)
    end

    println(cnt)
end

main()