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

int binSearch(VI v,int p){
	int l = 0,r = v.size()-1;
	int res = 0;
	while(r > l){
		int m = (l+r)/2;
		if(v[m] <= p){
			res = m; l = m+1;
		}
		else{
			r = m;
		}
	}
	return res;
}

int main()
{
	int n;
	SD(n);
	VI v(n);
	for (int i = 0; i < n; ++i)
	{
		SD(v[i]);
	}

	int p,q;
	SD(p);
	SD(q);

	sort(ALL(v));

	int res = p;
	int maxe = -MAX;
	for (int i = p; i <= q; ++i)
	{
		int minNum;
		int t = binSearch(v,i);
		if(t<n-1){
			minNum = min(abs(i-v[t]), abs(i-v[t+1]));
		}
		else {
			minNum = abs(i-v[t]);
		}
		// printf("%d  ",minNum );
		if(maxe < minNum){
			res = i;
			maxe = minNum;
		}
	}
	printf("%d", res);

	
	return 0;
}
