def tripnach(n):
    if n == 1:
        return 0
    elif n == 2:
        return 0
    elif n == 3:
        return 1
    else:
        return tripnach(n-1) + tripnach(n-2) + tripnach(n-3) 

def main():
    n = int(input())
    ans = tripnach(n)

    print(ans)
if __name__=='__main__':
    main()