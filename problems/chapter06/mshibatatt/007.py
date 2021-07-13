# https://atcoder.jp/contests/arc101/tasks/arc101_b

N = int(input())
a = list(map(int, input().split()))

left = min(a) - 1
right = max(a) + 1

while right - left > 1:
    mid = left + (right - left)//2
    if hogehoge:
        right = mid
    else:
        left = mid

print(right)