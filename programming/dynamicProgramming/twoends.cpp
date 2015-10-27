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

int solve(VI &v, int a, int b, std::vector<vector<int> > &dp)
{
	if(a>b)
		return 0;
	if(a==b)
		return v[a];

	if(dp[a][b]!=-1)
		return dp[a][b];
	CO<<"a="<<a<<' '<<"b="<< ' '<<b<<EL; 
	int n = v.size();
	dp[a][b] = max( v[a] +  v[a+1]>v[b]?solve(v,a+2,b,dp):solve(v,a+1,b-1,dp),
					v[b] +   v[a]>v[b-1]?solve(v,a+1,b-1,dp):solve(v,a,b-2,dp)  );
	return dp[a][b];

}

void print2d(std::vector<VI> &dp){
	for (int i = 0; i < dp.size(); ++i)
	{
		for(int v : dp[i])
			CO<<v<<' ';
		CO<<EL;
	}
}

int main()
{
	int n;
	cin>>n;
	VI v(n,0);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		/* code */
	}
	vector< vector<int> > dp(n, vector<int>(n,-1));	
	solve(v,0,n-1,dp);
	print2d(dp);
	return 0;
}
