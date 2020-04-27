def gcd(a,b):
	if (a == 0):
		return b
	return gcd(b%a, a)

for _ in range(int(input())):
	n = int(input())
	l = [ [i,1] for i in range(1,n + 1)]
	if n == 1:
		print(1)
	else : print(n//2)
	for x in range(len(l)):
		mul = l[x][0]
		if l[x][1] == 0:
			continue
		# print(l[x][0], end = " ")
		lt = [l[x][0]]
		for y in range(x+1,len(l)):
			if l[y][1] != 0 and gcd(mul,l[y][0]) == 1:
				mul *= l[y][0]
				l[y][1] = 0
				lt.append(l[y][0])
				# print(l[y][0], end = " ")
		print(len(lt),*lt)
			