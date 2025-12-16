t = int(input())

for _ in range(t):
  n = int(input())
  a = [int(num) for num in input().split(" ")]
  max_num = []
  for num in a:
    if len(max_num) == 0:
      max_num.append(num)
    else:
      max_num.append(max(max_num[-1], num))
  count = 0
  for i in range(n):
    if i > 0:
      if a[i] < max_num[i - 1]:
        count += 1
  
  print(count)