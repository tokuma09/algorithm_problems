# https://atcoder.jp/contests/arc101/tasks/arc101_b
from itertools import accumulate
'''
median of m_lr where m_lr is median of a[l:r] (l <= r)
<=> max x s.t. n(m_lr < x) < (N(N+1)/2)//2)+1

<=> max x s.t. count of [l,r] < (N(N+1)/2)//2)+1
    s.t. n(a_i < x) > n(a_j >= x) where all a in [l, r]

<=> max x s.t. count of [l, r] < (N(N+1)/2)//2)+1  
    s.t. S_q_r - S_q_l-1 > 0 where S_q_i = sum_1^i q_i,
        where q_i = 1 if a_i < x else -1 

<=> max x s.t. count of [l, r] < (N(N+1)/2)//2)+1
    s.t. l <= r and  S_q_r > S_q_l-1,
        where S_q_i = sum_1^i q_i,
        where q_i = 1 if a_i < x else -1 

The condition is True if x = min(a)
The condition is False if x = max(a)
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

def main():
    N = int(input())
    a = list(map(int, input().split()))

    left = 1
    right = max(a) + 1
    threshold = (N*(N+1)/2)//2 + 1

    while right - left > 1:
        mid = left + (right - left)//2
        a_x = [0]+[1 if i < mid else -1 for i in a]
        qusai_inv = 0
        bit = Bit(2*N+2)
        
        for i, e in enumerate(accumulate(a_x)):
            bit.add(e+N+1, 1)
            qusai_inv += bit.sum(e+N)
            
        if qusai_inv < threshold:
            left = mid
        else:
            right = mid

    print(left)

if __name__=='__main__':
    main()