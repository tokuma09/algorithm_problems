def main():
  # N = int(input()) # switch with next line in atCoder
  N, W = map(int, input().split())
  p = list(map(int, input().split()))
  # W = sum(p) # drop comment out in atCoder
  
  # dp[i][j] is True if you can make j from p0,...,pi else False 
  dp = [[None]*(W+1) for i in range(N)]
   
  for i in range(N):
    for j in range(W+1):
      if i == 0:
        dp[i][j] = True if p[i] == j or j == 0 else False
      else:
        dp[i][j] = True if dp[i-1][j] == True or \
        					(p[i] < j and dp[i-1][j-p[i]] == True) or \
          					(p[i] == j) \
        				else False
  
  output = sum(dp[N-1])
  print(output)
  
if __name__=='__main__':
  main()