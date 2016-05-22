# import psyco
# psyco.full()
import sys
def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmar(a,n):
	mid = n/2
	if(n==1):
		return a[0]
	if(n==2):
		return lcm(a[0],a[1])
	return lcm(lcmar(a[0:mid],mid),lcmar(a[mid:],n-mid))

def printlcm(a,n):
	mul = lcmar(a,n)
	mul = mul % 1000000007
	print mul
def input_arr(n):
	a = sys.stdin.readline().rstrip().split(' ')
	b=(n+1)*[0]
	for i in range(0,n):
		b[i+1] = int(a[i])
	return b

def main():
	t = int(sys.stdin.readline().rstrip());
	while(t):
		t-=1
		n = int(sys.stdin.readline().rstrip());
		a = input_arr(n)
		iscalc = (n+1)*[0]
		klen = []
		ll=0
		for i in range(1,n+1):
			if(iscalc[i]==0):
				iscalc[i]=1
				pr = a[i]
				tl = 1;
				while pr!=i:
					iscalc[i] = 1
					tl+=1
					pr = a[pr]
				klen.append(tl)
				ll+=1
		printlcm(klen,ll)
main()