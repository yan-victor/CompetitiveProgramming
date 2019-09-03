#include<bits/stdc++.h>

using namespace std;

int phi(int n,int x) {
	int ans = x;
	for(int i=5;i*i<=n;i+=(i%6==1 ? 4 : 2)) {
		if(n%i==0) {
			while(n%i==0) {
				n/=i;
			}
			ans-=ans/i;
		}
	}
	if(n>1) {
		ans-=ans/n;
	}
	return ans;
}


