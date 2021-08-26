# 3.7

def main():
    s = input()
    output = 0

    for i in range(2**(len(s)-1)):
        # "+"のはいりうる場所を2進数で表現
        binary = format(i, '0'+str(len(s)-1)+'b')
        
        formula = s
        counter = 0
        
        for j in range(len(binary)):    
            if binary[j] == '1':
                formula = formula[:counter+j+1] + '+' + formula[counter+j+1:]
                counter += 1
        
        output += eval(formula)

    print(output)

if __name__=='__main__':
    main()
