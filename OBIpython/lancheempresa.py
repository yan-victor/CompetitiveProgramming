#Yan Victor
#OBI 2008 Fase 2 - P2

INF = 10000000

s,c = map(int,input().split())
dis = [[INF for i in range(s+1)] for j in range(s+1)]

for i in range(s+1):
	dis[i][i] = 0

for i in range(c):
	a,b,d = map(int,input().split())
	dis[a][b] = dis[b][a] = d

for k in range(1,s+1):
	for i in range(1,s+1):
		for j in range(1,s+1):
			if(dis[i][k]+dis[k][j]<dis[i][j]):
				dis[i][j] = dis[j][i] = dis[i][k]+dis[k][j]

resp = INF

for i in range(1,s+1):
	maior = 0
	for j in range(1,s+1):
		maior = max(maior,dis[i][j])
	if maior<resp:
		resp = maior
print(resp)