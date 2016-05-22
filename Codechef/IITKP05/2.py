def power(x,p):
	if(p==0):
		return 1
	else:
		half = power(x,p/2);
		half *= half
		if(p&1):
			half*=x
		return half
def power_mod(x,p,n):
	if(p==0):
		return 1
	else:
		half = power_mod(x,p/2,n)
		half = (half*half)%n
		if(p&1):
			half = half*x
			half%=n
		return half
def compute(x,m,n):
	if(m==0):
		return 1
	elif (m&1):
		t = compute(x,m/2,n)
		ans = t*(1+ power_mod(x,m/2+1,n))
		# print ans
		return ans%n
	else:
		t = compute(x,m/2-1,n)
		ans = 1 + x*t + power_mod(x,m/2+1,n)*t
		# print ans
		return ans%n
def main(str):
	t = int(str)
	while(t!=0):
		s = raw_input().split(' ')
		x = int(s[0])
		m = int(s[1])
		n = int(s[2])
		# print x,m,n
		# ans = (power(x,m+1) - 1)/(x-1)
		# ans %= n
		print compute(x,m,n)
		t-=1
while True :
    try:
        main(raw_input())
    except:
        break