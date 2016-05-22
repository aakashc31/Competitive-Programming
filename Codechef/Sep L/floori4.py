import math
def sum_power_4(n,m):
    return (((n*(n+1)*(2*n+1)*(3*n*n+3*n-1))/30)%m)
def s_range(a,b,m):
	return ((sum_power_4(b,m) + (((m-1)*(sum_power_4(a-1,m)))%m))%m)

def power_mod_4(n,m):
	return (n**4)%m;

def runner(n,m):
	root = int(math.sqrt(n))
	i = 1;
	s=0;
	while(i<=root):
		s = s+ (power_mod_4(i,m)*(n/i))%m
		s = s%m
		i += 1
	den, ub, lb = 1,n,n/2
	while(True):
		ub = n/den
		lb = (n/(den+1))+1
		if(lb<=root):
			lb = root+1
			s = s+(den*s_range(lb,ub,m))%m
			s = s%m
			break;
		else:
			s = s+(den*s_range(lb,ub,m))%m
			s = s%m
		den += 1
	print s

def main():
	t = int(raw_input())
	i = 1
	while i<=t:
		inp = raw_input();
		(a,b) = inp.split(' ')
		a = int(a)
		b = int(b)
		runner(a,b)
		i+=1
main()