#Yan Victor
#OBI P2 2018 - Muro
n = int(input())
f = [-1 for i in range(10001)]
f[0] = f[1] = 1
f[2] = 5
resto = 1000000007

for i in range(3,n+1):
	f[i] = (f[i-1]+4*f[i-2]+2*f[i-3])%resto
print(f[n])
