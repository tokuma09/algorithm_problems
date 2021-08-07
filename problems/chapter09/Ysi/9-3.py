from collections import deque
def main():
    N = int(input())
    S = list(input())

    cumsum = [0]
    for i in range(2*N):
        if S[i] == "(":
            a = 1
        elif S[i] == ")":
            a = -1
        cumsum.append(cumsum[i] + a)
    
    is_ok = True
    if not cumsum[-1] == 0:
        is_ok = False
    for i in range(2*N + 1):
        if cumsum[i] < 0:
            is_ok = False
    
    
    
    if is_ok == False:
        print("No")
    else:
        stack = deque()
        
        for i in range(2*N):
            if S[i] == "(":
                stack.append(i+1)
            elif S[i] == ")":
                left = stack.pop()
                print(left, i + 1)
if __name__=='__main__':
    main()