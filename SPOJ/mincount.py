def compute(n):
	n = n*(n+1)
	n = n//6
	return n

def main():
	t = int(input())
	i = 0
	while i < t:
		n = int(input())
		print(compute(n))
		i+=1

main()