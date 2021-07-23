using DataStructures

function main()
    N, M = parse.(Int, split(readline()))
    As, Bs = zeros(Int, M), zeros(Int, M)
    for i in 1:M
        As[i], Bs[i] = parse.(Int, split(readline()))
    end

    ans = 0
    for i in 1:M
        ds = IntDisjointSets(N)
        for j in 1:M
            if j ≠ i
                union!(ds, As[j], Bs[j])
            end
        end

        cnt = 0
        for j in 1:N
            if j == find_root(ds, j)
                cnt += 1
            end
        end

        if cnt > 1
            ans += 1
        end
    end


    println(ans)
end

main()