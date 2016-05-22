modulo = 1000000007;
inv = 500000004;
def partfunc(a,b):
	s = (a*b*(a+1))/2 + a
	s *= ((b-1)*(b))/2
	s %= modulo
	return s

def check(a,b):
	s = 0
	x = 1
	m = (b-1)*(a*b+1)
	while x<=m:
		q = x/b
		r = x%b
		if r>0:
			if q%r==0 and q/r <= a and q/r >= 1:
				s += x
		x += 1
	return s

def main():
	r = raw_input().split(' ')
	a = int(r[0])
	b = int(r[1])
	print partfunc(a,b)
	# print check(a,b)

main()