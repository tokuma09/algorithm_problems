from collections import deque

def main():
    express = input()
    stack = deque([])
    output = []
    cumsum = [0] # if cumsum become negative, then invalid 
    for i, e in enumerate(express):
        if e == '(':
            stack.append(i)
            a = 1
        elif e == ')':
            pair = [stack.pop(), i]
            output.append(pair)
            a = -1
        cumsum.append(cumsum[i] + a)
        if cumsum[-1] < 0:
            is_ok = False
            break 
    
    if cumsum[-1] == 0:
        is_ok = True
    else:
        is_ok = False

    if is_ok:
        print(is_ok)
        print(output)
    else:
        print(is_ok)


if __name__=='__main__':
    main()