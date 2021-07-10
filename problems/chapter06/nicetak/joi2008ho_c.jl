function main()
    N, M = parse.(Int, split(readline()))
    ps = [parse(Int, readline()) for _ in 1:N]

    push!(ps, 0)
    pars = [p₁ + p₂ for p₁ in ps for p₂ in ps]
    sort!(pars)

    ans = 0
    for par in pars
        if par ≤ M
            idx_insert = searchsortedfirst(pars, M-par) - 1
            tmp = (idx_insert == 0) ? par : par + pars[idx_insert]
            ans = max(ans, tmp)
        end
    end

    println(ans)
end

main()