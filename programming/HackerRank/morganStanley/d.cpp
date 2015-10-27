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
typedef long long  ll;
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
#define in(a,b)                     ( (b).find(a) != (b).end())

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define F first
#define S second
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




ll power(ll x,ll n){
	if(n==0)
		return 1;
	if(n==1)
		return x%MOD;
	ll res = power(x,n/2);

	if(n%2==0)
		return res*res %MOD;
	else
		return res*res*x %MOD;

}


ll get(int n){

	if(n==1)
		return 1;
	if(n==2)
		return 6;
	// n = n-2;
	ll num = (13*power(3,n-2)-1)%MOD;
	ll den = power(2,MOD-2) % MOD;
	return (num * den)% MOD;

}


int main()
{
	// CO<<-123%MOD;
	int tCases;
	SD(tCases);
	while(tCases--){

		int n;
		SD(n);

		ll wa = power(2,n-1);
		ll res = get(n) - wa;


		if(res>=0)
			printf("%lld\n",res);
		else
			printf("%lld\n",(res+MOD)%MOD);


	}


	return 0;
}
	