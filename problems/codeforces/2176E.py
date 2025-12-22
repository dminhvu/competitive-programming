import sys

input = sys.stdin.readline
# print = sys.stdout.write


"""
TODO: The solution is incomplete.

5 5 8 10 4 3 4 10 5 5
10 3 9 6 9 8 7 8 10 3

18
21

pref[1] = 10
pref[2] = 6
pref[3] = 9
pref[4] = 12
pref[5] = 9
pref[6] = 8
pref[7] = 14
pref[8] = 21
pref[9] = 10
pref[10] = 6

suff[10] = 3
suff[9] = 6
suff[8] = 9
suff[7] = 7
suff[6] = 8
suff[5] = 16
suff[4] = 18
suff[3] = 9
suff[2] = 3
suff[1] = 6

3*4 + 9 + 7*3 + 3*2 = 47 - 7 = 40

###
5 8 10 4 3 4 10 5 5
3 9 6 9 8 7 8 10 3

###
5 10 4 3 4 10 5 5
3 6 9 8 7 8 10 3

###
5 4 3 4 10 5 5
3 9 8 7 8 10 3

###
5 4 3 4 10 5
3 9 8 7 8 3

###
5 4 3 4 5
3 9 8 7 3

###
5 4 3 4 5
3 9 8 7 3

###
4 3 4 5
9 8 7 3

###
4 3 4
9 8 7

###
3
8


"""

a = [5, 5, 8, 10, 4, 3, 4, 10, 5, 5]
c = [10, 3, 9, 6, 9, 8, 7, 8, 10, 3]

v = [(ai, ci, i + 1) for i, (ai, ci) in enumerate(zip(a, c))]
v.sort(key=lambda x: x[0] / x[1], reverse=True)
print(v)
