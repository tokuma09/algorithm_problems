def memorize(func):
    memo = {}
    def helper(x):
        if not (x in memo):
            memo[x] = func(x)

        return memo[x]
    return helper

def tripnach(n):
    if n == 1:
        return 0
    elif n == 2:
        return 0
    elif n == 3:
        return 1
    else:
        return tripnach(n-1) + tripnach(n-2) + tripnach(n-3)

def main():
    n = int(input())

    func = memorize(tripnach)

    print(func(n))
if __name__=='__main__':
    main()