from collections import deque

def main():
    express = input()
    stack = deque([])
    output = []
    for i, e in enumerate(express):
        if e == '(':
            stack.append(i)
        elif e == ')':
            pair = [stack.pop(), i]
            output.append(pair)

    print(output)

if __name__=='__main__':
    main()