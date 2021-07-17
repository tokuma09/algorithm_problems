# http://poj.org/problem?id=2456

def is_feasible(distance, N, C, x):
    last_position = 0
    cow_number = 1
    for i in range(1, N):
        if x[i]-x[last_position] < distance:
            last_position = i
            cow_number += 1
            if cow_number == C:
                return True
    return False

def main():
    N, C = map(int, input().split())
    x = [int(input()) for _ in range(N)]
    x.sort()

    left = 0
    right = max(x)
    while right - left > 1:
        mid = left + (right - left)//2
        if is_feasible(mid, N, C, x):
            left = mid
        else:
            right = mid

    print(left)

if __name__=='__main__':
    main()