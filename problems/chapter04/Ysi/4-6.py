def rec(i, w, a, wlist):
    if i==0:
        if w==0:
            wlist[0] = True
            return True
        else:
            return False
    
    if wlist[w]:
        return True

    if rec(i-1, w, a, wlist):
        wlist[w] = True
        return True

    if rec(i-1, w-a[i-1], a, wlist):
        wlist[w - a[i-1]] = True
        return True

def main():
    n, w = map(int, input().split())
    a = list(map(int, input().split()))
    wlist = [False for i in range(w+1)]

    if rec(n, w, a, wlist):
        print("Yes")
    else:
        print("No") 

if __name__=='__main__':
    main()