import sys
sys.setrecursionlimit(10**6)

memo = {}

def getCombo(targetSum, currentSum, faces):
  if (currentSum > targetSum):
    return 0
  if (currentSum == targetSum):
    return 1

  if currentSum in memo:
    return memo[currentSum];

  combos = 0;
  for i in range(1,faces+1):
    combos += getCombo(targetSum, currentSum + i, faces);
    memo[currentSum] = combos
    return memo[currentSum]

n = int(input())
while n > 0:
    S, m = map(int, input().split())
    memo.clear()
    print(getCombo(S,0,m))
    n-=1