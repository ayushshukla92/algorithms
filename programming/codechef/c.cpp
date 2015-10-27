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
#define all(a)                      a.begin(), a.end()
#define IN(a,b)                      (b).find(a) != (b).end()

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
#define MAX 1000
#define MOD 1000000007
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
	int n,m,c;
	SD(n);
	SD(m);
	SD(c);

	unordered_map<int,int> u;
	unordered_map<int,int> l;
	for (int i = 0; i < n; ++i)
	{
		int t;SD(t);
		u[t]++;
	}
	for (int i = 0; i < m; ++i)
	{
		int t;SD(t);
		l[t]++;
	}
	VI match;
	for (int i = 1; i <= MAX; ++i)
	{
		if(IN(i,l) && IN(i,u)){
			match.PB(l[i]*u[i]%MOD);
		}
	}
	// print(match);
	int tot = match.size();
	std::vector<std::vector<ll> > dp(c+1,std::vector<ll>(tot+1,0) );
	for (int i = 0; i < tot; ++i)
	{
		dp[0][i] = (long)match[i];
	}
	// print(dp[0]);
	for (int i = 1; i <= c; ++i)
	{
		ll prev = dp[i-1][i-1];
		for (int j = i; j < tot; ++j)
		{
			dp[i][j] = prev;
			prev = (prev + dp[i-1][j])%MOD;
		}
		ll res = 0;
		for (int j = i; j < tot; ++j)
		{
			res = (res + dp[i][j])%MOD;
		}
		printf("%lld ",res );
	}

	return 0;
}
