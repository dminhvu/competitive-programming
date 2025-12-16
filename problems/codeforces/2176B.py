t = int(input())

for _ in range(t):
  n = int(input())
  s = input()
  s += s

  longest_zeroes = 0
  current_counter = 0
  for i in range(2*n):
    if s[i] == "0":
      current_counter += 1
    else:
      current_counter = 0
    longest_zeroes = max(longest_zeroes, current_counter)

  print(longest_zeroes)