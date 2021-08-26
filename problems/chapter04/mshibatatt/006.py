def bool_func(i, w, a):
    if i == 0:
        if w == 0:
            return True
        else:
            return False

    # in case not choosing a[i-1]
    if bool_func(i-1, w, a): 
        return True

    # in case choosing a[i-1]
    if bool_func(i-1, w-a[i-1], a): return True
    
    # return False if both cases are False
    return False

def main():
    N, W = map(int, input().split())
    a = list(map(int, input().split()))

    if bool_func(N, W, a): 
        print("Yes")
    else:
        print("No") 

######### memo verson ##########

def bool_func_memo(i, w, a, memo):
    if i == 0:
        if w == 0:
            return True
        else:
            return False

    # in case not choosing a[i-1]
    if memo[i-1][w] == float('inf'):
        memo[i-1][w] = bool_func(i-1, w, a, memo)
    if memo[i-1][w]:
        return True

    # in case choosing a[i-1]
    if memo[i-1][w-a[i-1]] == float('inf'):
        memo[i-1][w-a[i-1]] = bool_func(i-1, w-a[i-1], memo)
    if memo[i-1][w-a[i-1]]:
         return True
    
    # return False if both cases are False
    return False

def main_memo():
    N, W = map(int, input().split())
    a = list(map(int, input().split()))
    memo = [float('inf')]*N*W

    if bool_func(N, W, a): 
        print("Yes")
    else:
        print("No") 

if __name__=='__main__':
    #main()
    main_memo()