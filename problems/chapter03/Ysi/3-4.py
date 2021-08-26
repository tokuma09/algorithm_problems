def main():
    n = int(input())
    a = list(map(int, input().split()))

    minValue = 10 ** 9
    maxValue = - (10 ** 9)

    for i in range(n):
        if a[i] > maxValue:
            maxValue = a[i]
        if a[i] < minValue:
            minValue = a[i]
        
    print(maxValue - minValue)

if __name__=="__main__":
    main()