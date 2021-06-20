def count_753(start_string, N):
    # 特定の数値から始まるN以下の753数をカウント
    # 7,5,3をそれぞれ加えて再帰的に実行
    if int(start_string) > N:
        return 0
    count = 1 if all(i in start_string for i in '753') else 0 
    for i in '753':
        count += count_753(start_string + i, N)
    return count

def main():
    N = int(input())
    output = count_753('0', N)
    print(output)

if __name__=='__main__':
    main()