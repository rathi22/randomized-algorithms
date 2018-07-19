#include <bits/stdc++.h>
using namespace std;
#define MAX 105
#define mp make_pair
#define pb push_back
#define ip pair<int,int>
#define ff first
#define ss second
/*
	Global Minimum Cut of an unweight directed graph using
	Contraction Algorithm. Let us assume
	that the graph has n vertices numbered 1 to n and m edges.

	Probability of finding a global min-cut is calculated to be
	at least 2/n*(n-1). Hence, running O(n*n*logn) instances of
	the algorithm will give neglible failure probability. 
*/

int parent[MAX];
int r[MAX];

int find_set(int u){
	if(parent[u] == u)
		return u;
	return parent[u] = find_set(parent[u]);
}

void union_set(int u, int v){
	u = find_set(u);
	v = find_set(v);
	if(r[u]<r[v])
		swap(u,v);
	parent[v] = u;
	if(r[u]==r[v])
		++r[u];
}

int main(){
	srand(time(NULL));
	int n,m,u,v;
	cin>>n>>m;
	vector<int> adj[n+1];
	pair<bool,ip> edges[m];
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		edges[i] = mp(1,mp(u,v));
	}

	for(int i=1;i<=n;i++){
		r[i] = 0;
		parent[i] = i;
	}

	int num = n;
	int k = m;
	while(num>2){
		for(int i=0;i<m;i++){
			if(edges[i].ff){
				u = edges[i].ss.ff;
				u = find_set(u);
				v = edges[i].ss.ss;
				v = find_set(v);
				if(u == v){
					edges[i].ff = 0;
					--k;
					continue;
				}
			}
		}
		
		int idx = rand()%k;
		for(int i=0;i<m;i++){
			if(edges[i].ff){
				if(idx == 0){
					u = edges[i].ss.ff;
					u = find_set(u);
					v = edges[i].ss.ss;
					v = find_set(v);
					union_set(u,v);
					break;
				}
				--idx;
			}
		}
		--num;
	}

	map<int,vector<int> > mymap;
	map<int,vector<int> >::iterator it;
	for(int i=1;i<=n;i++)
		mymap[find_set(i)].pb(i);
	cout<<"Min Cut:\n";
	for(it=mymap.begin(); it!=mymap.end(); it++){
		vector<int> cut(it->second);
		for(int i=0;i<cut.size();i++)
			cout<<cut[i]<<" ";
		cout<<endl;
	}
}