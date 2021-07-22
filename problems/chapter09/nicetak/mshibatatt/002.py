from collections import deque

def main():
    express = input().split()

    item = deque([])
    for i in express:
        if i.isdecimal():
            item.append(i)
        else:
            output = item.pop()
            output = item.pop() + i + output
            item.append(str(eval(output)))

    output = item.pop()
    print(output)

if __name__=='__main__':
    main()