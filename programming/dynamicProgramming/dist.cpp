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
#include <stack>

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector < pair<int,int> > VP;
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
#define F first
#define S second

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

int main()
{
	int n;
	cin>>n;
	VI v(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		// int t;
		cin>>v[i];
	}

	VI dp(n+1,1000005);
	dp[0] = 0;

	VI cums(n+1,0);
	cums[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cums[i] = cums[i-1] + v[i-1];
	}

	for(int i = 1;i<=n;i++){
		for(int j=0;j<i;j++){

			int dist = cums[i] - cums[j];

			dp[i] = min(dp[i],(dist-100)*(dist-100) + dp[j] );
		}
		print(dp);
	}
	CO<<dp[n];

	return 0;
}
