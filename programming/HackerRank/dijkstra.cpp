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
#define MAX 100000007

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

void dijkstra(unordered_map<int,std::vector<PII> > &g,int s,int n){

	VI dist(n+1,MAX);
	dist[s] = 0;
	VB marked(n+1,false);
	// marked[s] = true;
	for (int i = 0; i < n; ++i)
	{
		int minI=0,minE = MAX;
		for (int j = 1; j <= n; ++j)
		{	
				// CO<<"nopeeeee";
			if(dist[j] < minE && !marked[j]){
				minE = dist[j];
				minI = j;
			}
		}
		marked[minI] = true;
		// printf("**minI =%d  %d***\n",minI,(int)g[minI].size() );
		for(PII child : g[minI]){
			if(dist[child.F] > dist[minI] + child.S){
				dist[child.F] = dist[minI] + child.S;

			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(i==s)
			continue;
		if(marked[i]){
			printf("%d ",dist[i] );
		}
		else{
			printf("-1 ");
		}
	}

}

int main()
{
	
	int tc;
	SD(tc);
	while(tc--){

		int n,m;
		SD(n);
		SD(m);
		unordered_map<int,std::vector<PII> > g;
		while(m--){
			int l,r,w;
			SD(l);SD(r);SD(w);
			g[l].PB({r,w});
			g[r].PB({l,w});
		}
		int s;
		SD(s);
		dijkstra(g,s,n);
	}

	return 0;
}
