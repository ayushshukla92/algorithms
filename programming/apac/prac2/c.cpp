#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <list>

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define inf 10000009

template <typename T>
 void print(vector<T> &v) 
{ 
	int c=0;
    for(T t : v){
    	cout<<"i"<<c<<": ";
    	cout<<t<<' ';
    	c++;
    }
    CO<<EL;
} 

int check(int n, unordered_set<int> nums){

	int res=0;
	while(n!=0){
		if(nums.find(n%10)==nums.end())
			return -1;
		n = n/10;
		res++;

	}
	return res;

}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		unordered_set<int> nums;
		int q; cin>>q;
		VI dp(q+1,inf);
		for (int i = 0; i < 10; ++i)
		{
			char c;
			cin>>c;
			if(c=='1'){
				nums.insert(i);
				dp[i] = 1;
			}
		}
		// CO<<check(30,nums);



		for(int i = 2;i <= queue; i++){

			int cur = check(i,nums);
			if(cur!=-1){
				dp[i] = cur;
			}
			else{
				int res = inf;
				for(int k = 2; k<=i ; k++){
					if(i%k==0){
						res = min(res,dp[k]+dp[i/k]+1);
					}

				}
				dp[i]=res;
			}


		}
		for(int i =0;i<dp.size();i++)
			dp[i] = dp[i]+1;
		CO<<dp[q];

		
	}

	return 0;
}
