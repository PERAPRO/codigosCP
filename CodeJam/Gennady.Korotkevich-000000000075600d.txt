t = int(input())
for _ in range(t):
  n = int(input())
  x = list(map(int, input().split()))
  ans = 0
  for i in range(1, n):
    L = x[i]
    R = x[i]
    while R <= x[i - 1]:
      L = L * 10 + 0
      R = R * 10 + 9
      ans += 1
    x[i] = max(x[i - 1] + 1, L)
  print('Case #' + str(_ + 1) + ':', ans)
