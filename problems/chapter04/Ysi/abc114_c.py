n = int(input())
#ans = 0
def rec(currentValue, usedValue, counter):
    #global ans
    if currentValue > n:
        return
    if usedValue==7:
        #ans += 1
        counter.append(1)

    rec(currentValue*10 + 7, usedValue|1<<0, counter)
    rec(currentValue*10 + 5, usedValue|1<<1, counter)
    rec(currentValue*10 + 3, usedValue|1<<2, counter)
    
def main():
    ### globalにしてansを更新
    # rec(0, 0, ans)

    ### 以下のようにして配列にアクセスさせている記事を発見
    res =[]
    rec(0, 0, res)
    ans = sum(res)
    print(ans)

if __name__=='__main__':
    main()