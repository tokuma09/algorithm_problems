def main():
    k, s = map(int, input().split())

    count = 0
    for x in range(k+1):
        for y in range(k+1):
            if s - k <= x + y <= s:
                count +=1

    print(count)

if __name__=="__main__":
    main()