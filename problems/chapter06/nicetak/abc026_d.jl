function main()
    A, B, C = parse.(Float64, split(readline()))
    g(t; A=A, B=B, C=C) = A * t + B * sin(C * t * π) - 100
    t̲, t̄ = 0, (B + 100) / A
    ε = 1e-6

    t = (t̄ + t̲) / 2
    while abs(g(t)) > ε
        if g(t) > 0
            t̄ = t
        else
            t̲ = t
        end
        t = (t̄ + t̲) / 2
    end

    println(t)
    println()
end

main()