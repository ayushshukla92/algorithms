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
typedef vector < pair<int,int> > VP;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define inf 0x7fffffff

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
	// cin>>n;
	VI v = {3,5,2,7,1,7,5,2,8,9,1,25,15,8,3,1,38,45,8,1};
	n = v.size();

	vector<bool> dp(n,false);
	dp[0] = true;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum = sum + v[i];
	}

	if(sum%2!=0)
		CO<<"nope"<<EL;
	else
	{
		for (int i = 1; i < sum; ++i)
		{
			for(int cur : v){
				if(i-cur >=0 && dp[i-cur])
					dp[i] = true;
			}
		}

		if(dp[sum/2]) CO<<"YES"<<EL;
	}

	
	return 0;
}
