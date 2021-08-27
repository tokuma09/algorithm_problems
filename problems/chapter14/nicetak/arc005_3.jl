using DataStructures

function main()
    H, W = parse.(Int, split(readline()))
    mp = [readline() for _ = 1:H]

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    
    xₛ, yₛ, xₑ, yₑ = -1, -1, -1, -1
    for i = 1:H, j = 1:W
        if mp[i][j] == 's'
            xₛ, yₛ = i, j
        elseif mp[i][j] == 'g'
            xₑ, yₑ = i, j
        end
    end

    que = Deque{Tuple{Int, Int}}()
    pushfirst!(que, (xₛ, yₛ))
    dists = 10^9 * ones(Int, H, W)
    dists[xₛ, yₛ] = 0

    while !isempty(que)
        x, y = popfirst!(que)

        for d = 1:4
            x′ = x + dx[d]
            y′ = y + dy[d]

            if 1 ≤ x′ ≤ H && 1 ≤ y′ ≤ W
                if mp[x′][y′] == '#'
                    if dists[x′, y′] > dists[x, y] + 1
                        dists[x′, y′] = dists[x, y] + 1
                        push!(que, (x′, y′))
                    end
                else
                    if dists[x′, y′] > dists[x, y]
                        dists[x′, y′] = dists[x, y]
                        pushfirst!(que, (x′, y′))
                    end
                end
            end
        end
    end


    if dists[xₑ, yₑ] ≤ 2
        println("YES")
    else
        println("NO")
    end
        
end

main()