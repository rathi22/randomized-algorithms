#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Rabin-Miller primality test
int flag;
ll modexp(ll a, ll b, ll m){
	if(b==0)
		return 1;
	ll p = modexp(a,b/2,m);
	ll res = p*p%m;
	if(b&1)
		res = a*res%m;
	else if(res==1 && p>1 && p<m-1)
		flag = 1;
	return res;
}

// Failure probability of a single test is at most 1/4
bool Miller_Test(ll m, ll a){
	flag = 0;
	if(modexp(a,m-1,m)!=1 || flag)
		return 1;
	return 0;
}

int main(){
	ll m,a,t=200;
	cin>>m;
	// Assuming m>3. Corner cases may be handled separately
	while(t--){
		a = rand()%(m-3)+2;
		if(Miller_Test(m,a)){
			cout<<"Composite\n";
			return 0;
		}
	}
	cout<<"Prime\n";
}