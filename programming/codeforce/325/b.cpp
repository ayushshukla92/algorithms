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
	VI l(n,0);
	VI u(n,0);

	for (int i = 0; i < n-1; ++i)
	{
		int t;
		SD(t);
		u[i+1] = u[i] + t;
	}
	for (int i = 0; i < n-1; ++i)
	{
		int t;
		SD(t);
		l[i+1] = l[i] + t;
	}
	VI b(n,0);
	for (int i = 0; i < n; ++i)
	{
		SD(b[i]);
	}
	int min1=MAX,min2=MAX;



	for (int i = 0; i < n; ++i)
	{
		int cur = b[i] + u[i] + l[n-1]-l[i];
		if(cur<min1)
		{
			min2 = min1;
			min1 = cur;
		}
		else if(cur<min2)
			min2 = cur;
	}
	printf("%d\n", min1 + min2);

	return 0;
}
