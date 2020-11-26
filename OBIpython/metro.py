#Yan Victor
#OBI 2015 Fase 1 - PSenior

from collections import deque

n,m = map(int,input().split())
g = [[] for i in range(n+1)]
deg = [0 for i in range(n+1)]
mark = [0 for i in range(n+1)]

def bfs(x):
	fila = deque()
	fila.appendleft(x)
	while fila:
		u = fila.pop()
		mark[u] = 2
		for v in g[u]:
			if mark[v]==0 and deg[v]<=2:
				fila.appendleft(v)

for i in range(m):
	p,q = map(int,input().split())
	g[p].append(q)
	g[q].append(p)
	deg[p]+=1
	deg[q]+=1

centro = 0

for i in range(1,n+1):
	if(deg[i]==1):
		bfs(i)
	if(deg[i]>=5):
		centro = i
bfs(centro)

resp = 0
for i in range(1,n+1):
	if(mark[i]==0):
		resp+=1
print(resp)