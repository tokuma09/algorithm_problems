from collections import deque
def main():
    S = list(input())
    operator = ["+", "-", "*", "/"]
    stack = deque()
    for s in S:
        if not s in operator:
            s = int(s)
            stack.append(s)
        else:
            y = stack.pop()
            x = stack.pop()

            if s == "+":
                stack.append(x + y)
            elif s == "-":
                stack.append(x - y)
            elif s == "*":
                stack.append(x * y)
            else:
                # 割り算整数に閉じてないからどうしようか困りうるなあ
                stack.append(x // y)

    ans = stack.pop()   
    print(ans)
if __name__=='__main__':
    main()
