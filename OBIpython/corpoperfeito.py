#Yan Victor
#Autoral Neps - Em Busca do Corpo Perfeito
W,N = map(int,input().split())
p = [0]
v = [0]
dp = [[-1 for w in range(W+10)] for i in range(N+10)]

for i in range(1,N+1):
	peso,valor = map(int,input().split())
	p.append(peso)
	v.append(valor)

for w in range(W):
	dp[N+1][w]=0

for i in range(N,0,-1):
	for w in range(W+1):
		if(p[i]<=w):
			dp[i][w] = max(dp[i+1][w],dp[i+1][w-p[i]]+v[i])
		else:
			dp[i][w] = dp[i+1][w]
print(dp[1][W])