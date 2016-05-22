import random

def rand():
	return random.randrange(0,10**20)

def power_mod(n, p, modulo):
	if p==0:
		return 1%modulo
	a = 1
	sq = n
	while p > 0:
		if(p%2 == 1):
			a = (a*sq) % modulo
		sq = (sq * sq) % modulo
		p = p//2
	return a

def Miller(p, iteration):
	if(p<2):
		return False
	if(p!=2 and p%2==0):
		return False
	s = p-1
	while (s%2==0):
		s = s//2
	i = 0
	while i < iteration:
		a = rand()%(p-1) + 1
		temp = int(s)
		mod = power_mod(a, temp, p)
		while(temp!=p-1 and mod!=1 and mod!=p-1):
			mod = (mod * mod) % p
			temp = (temp*2)
		if(mod != p-1 and temp%2==0):
			return False
		i+=1
	return True

def main():
	t = int(input())
	while t > 0:
		n = int(input())
		if(Miller(n,20)):
			print("YES")
		else:
			print("NO")
		t-=1

main()
