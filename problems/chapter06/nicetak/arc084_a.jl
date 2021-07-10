function main()
    N = parse(Int, readline())
    As = parse.(Int, split(readline()))
    Bs = parse.(Int, split(readline()))
    Cs = parse.(Int, split(readline()))

    sort!(As)
    sort!(Bs)
    sort!(Cs)

    ans = 0
    nums_ab = [searchsortedfirst(As, b) - 1 for b in Bs]
    acc_nums_ab = cumsum(nums_ab)
    for c in Cs
        num_bc = searchsortedfirst(Bs, c) - 1
        if num_bc > 0
            ans += acc_nums_ab[num_bc]
        end
    end
    
    println(ans)
end

main()