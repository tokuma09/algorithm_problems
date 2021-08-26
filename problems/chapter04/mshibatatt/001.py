
def tribo(N):
    if N == 0 or N == 1: 
        return 0
    elif N == 2:
        return 1

    return tribo(N-1) + tribo(N-2)


def main():
    N = int(input())
    output = tribo(N)
    print(output)

if __name__=='__main__':
    main()    