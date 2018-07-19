#include <bits/stdc++.h>
using namespace std;

/*
	Contention Resolution Problem: n processes P1,..,Pn
	competing for access to a single shared database. Database
	can be accessed by atmose 1 process in a round. Processes 
	can't communicate with one another.

	Solution: Each process randomly accesses the database with
	some probability p>0. (Optimal 'p' turns out to be 1/n)
	
	Analysis suggests that expected number of rounds before
	each process can access the database is O(nlogn).

	For convenience, we number processes from 0 to n-1, and
	analyse over multiple values of n.
*/

int main(){
	srand(time(NULL));
	int values[10] = {2,5,10,20,50,100,500,1000,5000,10000};
	for(int i=0;i<10;i++){
		int n = values[i];
		vector<int> v(n,0);
		int process_id, count=0, rounds=0;
		while(count<n){
			++rounds;
			process_id = -1;
			for(int j=0;j<n;j++){
				if(rand()%n == 0){		// Happens with probability 1/n
					if(process_id<0)
						process_id = j;
					else
						process_id = n;
				}	
			}

			if(process_id>=0 && process_id<n){
				if(!v[process_id])
					++count;
				++v[process_id];
			}
		}
		cout<<"N="<<n<<" No.of Rounds="<<rounds<<endl;
	}

	/*
		Sample Output:

		N=2 No.of Rounds=4
		N=5 No.of Rounds=31
		N=10 No.of Rounds=140
		N=20 No.of Rounds=176
		N=50 No.of Rounds=472
		N=100 No.of Rounds=1449
		N=500 No.of Rounds=9966
		N=1000 No.of Rounds=19493
		N=5000 No.of Rounds=114714
		N=10000 No.of Rounds=284462

		Accuracy of output can be increased by increasing
		number of trials(=1 here)
	*/
}