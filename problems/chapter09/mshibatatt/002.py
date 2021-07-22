from collections import deque

def main():
    express = input().split()

    stack = deque([])
    for i in express:
        if i.isdecimal():
            stack.append(i)
        else:
            output = stack.pop()
            output = stack.pop() + i + output
            stack.append(str(eval(output)))

    output = stack.pop()
    print(output)

if __name__=='__main__':
    main()