# https://atcoder.jp/contests/abc131/tasks/abc131_d
 
def main():
    N = int(input())
    task = []
    for _ in range(N):
        task.append(list(map(int, input().split())))
    
    # sort by time limit
    task.sort(key=lambda x: x[1])
    t = 0
    output = 'Yes'
    for i in task:
        t += i[0]
        if t > i[1]:
            output = 'No'
            break
    
    print(output)

if __name__=='__main__':
    main()