#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
	To find the median, we define a general fn
	select(V,k), which returns the kth largest element
	in S. 

	Randomisation is involved in selecting a central splitter,
	so that the algorithm runs in O(n) time as compared to
	other standard O(nlogn) deterministic algorithms.
*/

ll select(vector<ll> v, ll k){
	int m = v.size();
	while(true){
		vector<ll> lo,hi;
		int idx = rand()%m;
		for(int i=0;i<m;i++){
			if(i == idx)
				continue;
			if(v[i]<v[idx])
				lo.push_back(v[i]);
			else
				hi.push_back(v[i]);
		}

		if(lo.size() == k-1)
			return v[idx];
		if(4*lo.size()>=m && 4*hi.size()>=m){
			if(k>lo.size())
				return select(hi,k-lo.size()-1);	
			else
				return select(lo,k);
		}	
	}
}

int main(){
	srand(time(NULL));
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<< select(a,(n+1)/2) <<endl;
}