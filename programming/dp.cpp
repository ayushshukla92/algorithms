#include <iostream>
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
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>


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

// Input macros
#define SD(n)    scanf("%d",&n)
#define SF(n)    scanf("%f",&n)
#define SLF(n)    scanf("%lf",&n)
#define SS(n)    scanf("%s",&n)

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MAX 1000000007

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

int solveDp(VI v, int cur,VI dp){
	int n =v.size();
	if(cur >= n)
		return 0;
	if(dp[cur]!=-1)
		return dp[cur];

	int csum = 0;
	int maxN = -1;
	for (int i = cur; i <= cur+2 && i<n; ++i)
	{
		
		csum += v[i];
		int isum = 0;
		int minN = MAX;
		for (int j = i+1; j <= i+3 && j<n; ++j)
		{
			// isum += v[j];
			minN = min(minN,  solveDp(v,j+1,dp));
		}
		if(minN == MAX) minN = 0;
		maxN = max(maxN,csum+minN);
	
	}
	dp[cur] = maxN;

	return dp[cur];
}

int main()
{
	int tCases;
	SD(tCases);
	while(tCases--){
		int n;
		SD(n);
		VI v(n,0);
		for (int i = 0; i < n; ++i)
		{
			SD(v[i]);
		}
		VI dp(n,-1);
		int ans = solveDp(v,0,dp);
		printf("%d\n", ans);
	}
	
	return 0;
}
