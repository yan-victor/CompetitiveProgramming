//RMQ Segment Tree
#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;

#define pii pair<int,int>
#define F first
#define S second
#define fe (2*x+1)
#define fd (2*x+2)
#define mid ((l+r)>>1)

int v[N];
int tree[4*N];

void buildmin(int x,int l,int r) {
	if(l==r) {
		tree[x]=v[l];
		return;
	} 
	buildmin(fe,l,mid);
	buildmin(fd,mid+1,r);
	tree[x]=min(tree[fe],tree[fd]);
}

void updmin(int x,int l,int r,int p,int val) {
	if(l==r) {
		tree[x]=val;
		return;
	}
	if(p<=mid) {
		updmin(fe,l,mid,p,val);
	} else {
		updmin(fd,mid+1,r,p,val);
	}
	tree[x]=min(tree[fe],tree[fd]);
}

pii querymin(int x,int l,int r,int ql,int qr) {
	if(ql>r||qr<l) return INF;
	if(ql<=l&&r<=qr) return tree[x];
	return min(querymin(fe,l,mid,ql,qr),querymin(fd,mid+1,r,ql,qr));
}


