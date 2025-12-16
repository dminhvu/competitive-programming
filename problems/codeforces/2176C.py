"""
Docstring for problems.codeforces.2176C

O + O = E
E + E = E
E + O = O | => O + O = E -> cannot have more than 1 odd value
O + E = O |

One odd needs one even and vice versa.
- case all even: max_k = 0
- case all odd:
  max_k = odd_sorted[0]
          if k % 2 == 0
          else 0
  # [1 1 1 1]: max_0 = 1, max_1 = 0, max_2 = 1, max_3 = 0
- case k odd:
  max_k = sum(odd_sorted[:k//2]) + sum(even_sorted[:k//2])
          if k // 2 < len(odd_sorted) and k // 2 < len(even_sorted)
          else 0
  # [1 2 3 4]: max_1 = 7, max_3 = 0
  # [1 1 3 4]: max_1 = 7, max_3 = 0
- case k even:
  max_k = odd_sorted[0] + (even_sorted[:k] if k > 0 else 0)
  # [1 2 3 4]: max_0 = 3, max_2 = 7

  # [1 2 3 4 5 6 7]:
  max_0 = 7
  max_1 = 13
  max_2 = 17
  max_3 = 19
  max_4 = 17
  max_5 = 19
  max_6 = 0
  # [4 1 3 1 2]:
  max_0 = 3
  max_1 = 7
  max_2 = 9
  max_3 = 7
  max_4 = 9

---

always take 1 odd
remaining: k - 1 evens
if len(even_sorted) >= k - 1:
    take even_sorted[:k - 1]
if not enough:
    -> need to use pairs of odd, or single evens for first picks that sum up to an even
    # [1 1 1 1 1 2 7]
    max_1 = 7
    max_2 = 9
    max_3: pick 7, need 2 more -> can only be two 1s, then max_2 = 7
    max_4: pick 7, need 3 more -> can be two 1s + 2, then max_3 = 7
    max_5: pick 7, need 4 more -> can be four 1s, then max_4 = 7
    max_6: pick 7, need 5 more -> can be four 1s + 2, then max_5 = 7
    max_7: pick 7, need 6 more -> cannot find a valid solution, need at least six 1s, then max_7 = 0
"""

t = int(input())

for _ in range(t):
    n = int(input())
    nums = [int(num) for num in input().split(" ")]
    odd = [num for num in nums if num % 2 == 1]
    even = [num for num in nums if num % 2 == 0]

    odd_sorted = sorted(odd, reverse=True)
    even_sorted = sorted(even, reverse=True)

    if len(odd_sorted) == 0:  # all even
        for k in range(n):
            print(0, end=" ")
    elif len(even_sorted) == 0:  # all odd
        for k in range(n):
            print(odd_sorted[0] if k % 2 == 0 else 0, end=" ")
    else:
        # [4 1 3 1 2]:
        # max_1 = 3
        # max_2 = 7
        # max_3 = 9
        # max_4 = 7
        # max_5 = 9
        even_length = len(even_sorted)
        odd_length = len(odd_sorted)

        even_prefix = [0]
        for k in range(1, n + 1):
            if k <= even_length:
                even_prefix.append(even_prefix[-1] + even_sorted[k - 1])
            max_k = odd_sorted[0]
            if even_length >= k - 1:
                max_k += even_prefix[k - 1]
            else:
                max_k += even_prefix[-1]
                extra = min(k - 1 - even_length, odd_length - 1)
                if extra % 2 == 1:
                    extra += 1
                    max_k -= even_sorted[-1]

                if extra > odd_length - 1:
                    max_k = 0

            print(max_k, end=" ")

    print()
