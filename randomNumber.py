import random as rd

range = int(input())
s = []
while (len(s) < range + 1):
	n = rd.randint(0, range)
	if n not in s:
		s.append(n)

for i in s:
	print(i, end =" ")
print()
