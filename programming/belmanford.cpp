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

bool hasNegC(unordered_map<int,std::vector<PII> > &g,int n,int s){
	VI d(n,MAX);
	VI p(n,-1);
	d[s] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for(PII child : g[j]){
				int node = child.F;
				int wt = child.S;
				if(d[node] > d[j] + wt){
					d[node] = d[j] + wt;
					p[node] = j;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for(PII child : g[i]){
			int node = child.F;
			int wt = child.S;
			if(d[node] > d[i] + wt)
				return true;
		}
	}
	return false;

}

int main()
{
	unordered_map<int,std::vector<PII> > g;
	g[0].PB({1,4});
	g[1].PB({2,5});
	g[2].PB({1,-5});
	if(hasNegC(g,3,0))
		printf("Has negative cycle\n");
	else
		printf("Good to go!\n");
	return 0;
}
