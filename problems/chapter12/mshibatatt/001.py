a = list(map(int, input().split()))

[i[0] for i in sorted(enumerate(a), key=lambda x:x[1])]