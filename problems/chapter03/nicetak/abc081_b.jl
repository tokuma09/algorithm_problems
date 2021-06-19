function main()
    N = parse(Int, readline())
    As = parse.(Int, split(readline()))

    flg = true
    cnt = -1
    while flg
        for i in 1:length(As)
            if As[i] % 2 == 0
                As[i] = As[i] / 2
            else
                flg = false
                break
            end
        end
        cnt += 1
    end
    println(cnt)
end    

main()
