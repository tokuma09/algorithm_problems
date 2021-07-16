# https://atcoder.jp/contests/arc101/tasks/arc101_b
from itertools import accumulate
'''
median of m_lr
<=> max x s.t. n(m_lr < x) < ceil(N(N+1)/2/2)
<=> max x s.t. count of [l,r) < ceil(N(N+1)/2/2)
    s.t. n(a_i < x) <= n(a_j >= x) where all a in [l, r)
<=> max x s.t. count of [l, r) < ceil(N(N+1)/2/2) s.t.  
    s.t. 0 <= S_q_r - S_q_l where S_q_i = sum_1^i q_i, where q_i = -1 if a_i < x else 1 
<=> max x s.t. count of [l, r) < ceil(N(N+1)/2/2) s.t.  
    s.t. l < r and  S_q_l <= S_q_r, where S_q_i = sum_1^i q_i, where q_i = -1 if a_i < x else 1 

'''
class Bit():
    def __init__(self, n) -> None:
        self.size = n
        self.tree = [0] * (n + 1)
    
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
    
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
# 使用例
# bit = Bit(10)     # 要素数を与えてインスタンス化
# bit.add(2, 10)    # a2に10を加える
# print(bit.sum(3)) # a1～a3の合計を返す => 10

def qusai_invertion_number(a, N, bit):
    output = 0
    for i, e in enumerate(a):
        bit.add(e, 1)
        output += bit.sum(e) - 1
        
    return output

def main():
    N = int(input())
    a = list(map(int, input().split()))

    left = min(a) - 1
    right = max(a) + 1

    while right - left > 1:
        mid = left + (right - left)//2
        a_x = [-1 if i < mid else 1 for i in a]
        a_x = [i + N for i in accumulate(a_x)] 
        
        qusai_inv = 0
        bit = Bit(2*N)
        
        for i, e in enumerate(a_x):
            qusai_inv += bit.sum(e) 
            bit.add(e, 1)
        
        if qusai_inv  < (N*(N+1)/2)//2+1:
            left = mid
        else:
            right = mid

    print(left)

if __name__=='__main__':
    main()