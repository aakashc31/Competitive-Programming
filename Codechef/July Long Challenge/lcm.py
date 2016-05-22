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

print lcmar([2,4,8],3)
