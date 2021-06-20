
def tribo(N, memo):
    if N == 0 or N == 1: 
        memo[N] = 0
        return 0
    elif N == 2:
        memo[N] = 1
        return 1
    
    if memo[N] != -1: 
        return memo[N]
    
    memo[N] = tribo(N-1, memo) + tribo(N-2, memo)
    return memo[N]

def main():
    N = int(input())
    memo = [-1] * (N+1)

    output = tribo(N, memo)

    print(output)
    


if __name__=='__main__':
    main()    