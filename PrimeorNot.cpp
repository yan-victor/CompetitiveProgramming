// SPOJ Problem PON
// SPOJ user: @genezio

#include<bits/stdc++.h>

using namespace std;

using u128 = __uint128_t; //Para multiplicar inteiros de 64 bits
#define ll long long

int primes[12] = {2,3,5,7,11,13,17,19,23,29,31,37}; //Só precisamos testar estas bases

ll fexp(ll x,ll y,ll mod) { 
	if(y==1) return x;
	if(y==0) return 1;
	if(y%2) return ((u128)x*fexp(x,y-1,mod))%mod;
	ll aux = fexp(x,y>>1,mod);
	return ((u128)aux*aux)%mod;
}

bool fermat_trial(ll x,ll r,ll d,ll mod) {
	x = fexp(x%mod,d,mod);
	if(x==1||x==mod-1) return true;
	for(int j=1;j<r;j++) {
		x = ((u128)x*x)%mod;
		if(x==mod-1) return true;
	}
	return false;
}

bool millerrabin(ll x,ll y) {
	if(x<4) return x==2||x==3;
	int r = 0;
	x--;
	while(!(x%2)) {
		x >>= 1;
		r++;
	}
	for(int i=0;i<12;i++) {
		if(y==primes[i]) return true;
		if(!fermat_trial(primes[i],r,x,y)) return false;
	}
	return true;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	for(int k=0;k<t;k++) {
		ll n;
		cin>>n;
		if(millerrabin(n,n)) cout<<"YES\n"; 
		else cout<<"NO\n";
	}
}
