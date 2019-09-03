#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

#define mid ((l+r)/2)

struct node {
	node *l,*r;
	long long int s;
	node() {
		s=0;
		l=NULL;
		r=NULL;
	}
	node(long long int val) {
		s=val;
	}
};

node* no[N];
int v[N];

void build(node *x,int l,int r) {
	if(l==r) {
		x->s=(long long int)v[l];
		return;
	}
	x->l=new node();
	x->r=new node();
	build(x->l,l,mid);
	build(x->r,mid+1,r);
	x->s = x->l->s + x->r->s;
}

void upd(node *pre,node *x,int l,int r,int p,int val) {
	if(l==r) {
		x->s=val;
		return;
	}
	if(p<=mid) {
		x->r=pre->r;
		x->l=new node();
		upd(pre->l,x->l,l,mid,p,val);
	} else {
		x->l=pre->l;
		x->r=new node();
		upd(pre->r,x->r,mid+1,r,p,val);
	}
	x->s = x->l->s + x->r->s;
}

long long int query(node *x,int l,int r,int ql,int qr) {
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return x->s;
	return query(x->l,l,mid,ql,qr)+query(x->r,mid+1,r,ql,qr);
}


