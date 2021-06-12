# 3.5

def main():
    N = int(input())
    s = list(map(int, input().split()))

    output = 0
    is_odd = 0

    while is_odd == 0:
        new_s = []
        for i in s:
            a, b = divmod(i, 2)
            new_s.append(a)
            is_odd = max(is_odd, b)
        if is_odd == 0:
            output += 1
            s = new_s

    print(output)

if __name__=='__main__':
    main()
