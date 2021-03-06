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

int main()
{
	int n;
	SD(n);
	VI a(n,0);
	VI p(n,0);
	VI cum(n,101);
	VI sum(n,0);
	for (int i = 0; i < n; ++i)
	{
		SD(a[i]);
		SD(p[i]);
		if(i==0){
			cum[i] = p[i];
			sum[i] = a[i];
		}
		else{
			cum[i] = min(cum[i-1],p[i]);
			sum[i] = sum[i-1] + a[i];  
		}

	}
	int res = 0;

	int prev = cum[0];
	int c = 1;
	int s = a[0];
	for (int i = 1; i < n; ++i)
	{
		if(prev == cum[i]){
			c++;
			s = s + a[i];
		}
		else{
			res += s*prev;
			s=a[i];
			c=1;
			prev = cum[i];
		}
	}
	if(prev == cum[n-1])
		res += s*prev;
	printf("%d", res);	

	
	return 0;
}
