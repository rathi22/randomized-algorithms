#include <bits/stdc++.h>
using namespace std;

/*
	In approximation 3-SAT, we search for a truth assignment
	that satisfy a substantial number of clauses. It can be 
	proved that the expected number of clauses satisfied by 
	a random assignment is k*7/8, where k is the optimal
	number of classes.

	Hence, the algorithm just keeps looking for such a truth
	assignment by randomly assigning 0 or 1 to each variable
*/

bool check(int a, int b, int c){
	if(a && b && c)
		return 0;
	return 1;
}

int main(){
	srand(time(NULL));
	int n,m; 	// Number of Variable, Number of Clauses
	cin>>n>>m;
	int a[m],b[m],c[m];
	// xi is denoted by i, and (not xi) by -i
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i]>>c[i];
	while(true){
		vector<int> v(n+1);
		for(int i=1;i<=n;i++)
			v[i] = rand()%2;
		int count = 0;
		for(int i=0;i<m;i++)
			if(check(v[abs(a[i])]^(a[i]>0),v[abs(b[i])]^(b[i]>0),v[abs(c[i])]^(c[i]>0)))
				++count;
		if(count*8 >= m*7){
			cout<<"Assignment:\n";
			for(int i=1;i<=n;i++)
				cout<<"x"<<i<<" = "<< v[i] <<endl;
			cout<<"Total Count = "<<count<<endl;
			break;
		}
	}
}	