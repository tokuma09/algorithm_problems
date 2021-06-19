def numDivided(num):
    count = 0
    while num % 2 == 0:
        num = num // 2
        count += 1
    
    return count

def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    minDiv = 100000000000
    for i in range(n):
        numDiv = numDivided(a[i])
        if numDiv < minDiv:
            minDiv = numDiv
    
    print(minDiv)

if __name__=='__main__':
    main()