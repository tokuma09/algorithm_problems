# 3.6

def main():
    K, N = map(int, input().split())
    output = 0

    for x in range(N+1):
        if 0 <= x <= K:
            for y in range(N+1-x):
                if 0 <= y <= K:
                    z = N - x - y
                    if 0 <= z <= K:
                        output += 1

    print(output)

if __name__=='__main__':
    main()