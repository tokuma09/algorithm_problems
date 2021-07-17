from bisect import bisect_left
n, m = map(int, input().split())
a = [0]
for i in range(n):
    a.append(int(input()))

a_1 = set()
for x in a:
    for y in a:
        a_1.add(x + y)
a_1 = list(a_1)
a_1.sort()
length = len(a_1)

ans = 0
for a1 in a_1:   
    i = bisect_left(a_1, m - a1)

    if i < length:
        if a1 + a_1[i] == m:
            ans = max(ans, a1 + a_1[i])
        else:
            if i > 0:
                ans = max(ans, a1 + a_1[i-1])
    else:
        ans = max(ans, a1 + a_1[i-1])

print(ans)
