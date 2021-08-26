def main():
  N, W, k= map(int, input().split())
  a = list(map(int, input().split()))
  
  # dp[i][j] is m if you can make j by choosing m from a0,...,ai, otherwise None
  dp = [[None]*(W+1) for i in range(N)]
   
  for i in range(N):
    for j in range(W+1):
      if i == 0:
        if a[i] == j: dp[i][j] = 1
      else:
        temp = []
        if a[i] < j and dp[i-1][j-a[i]] != None:
            temp.append(dp[i-1][j-a[i]] + 1) 
        if dp[i-1][j] != None:
            temp.append(dp[i-1][j]) 
        if a[i] == j:
            temp.append(1) 

        if len(temp) > 0:
            dp[i][j] = min(temp)
  
  output = 'Yes' if dp[N-1][W] <= k else 'No'
  print(output)
  
if __name__=='__main__':
  main()