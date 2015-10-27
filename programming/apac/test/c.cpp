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
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v) //foreach(it,map)
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
#define MAX 1000007

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,m;
		SD(n);SD(m);
		vector< vector<int> > g(n,std::vector<int>(n,MAX) );
		unordered_map<int, unordered_map<int,int> > road;
		map<PII,int> edges;
		for (int i = 0; i < m; ++i)
		{
			int a,b,c;
			SD(a);SD(b);SD(c);
			g[a][b] = c;
			g[b][a] = c;
			road[a][b] = i;
			road[b][a] = i;
			edges[{a,b}] = c;
			// edges.PB({a,b});

		}
		for (int i = 0; i < n; ++i)
		{
			g[i][i] = 0;
		}
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				
				for (int j = 0; j < n; ++j)
				{
					if(g[i][k] + g[k][j] < g[i][j]){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}

		VI used;
		for(auto e : edges){
			int n1 = e.F.F;
			int n2 = e.F.S;
			int wt = e.S;
			CO<<"checking"<<n1<<" * "<<n2<<" "<<EL;
			for (int i = 0; i < n; ++i)
			{
				for (int j = i+1; j < n; ++j)
				{
					// CO<<g[i][n1]<<" "<<wt<<" "<<g[j][n2]<<" "<<g[i][j]<<EL;
					if(g[i][n1] + wt + g[n2][j] == g[i][j] || g[j][n1] + wt + g[n2][i] == g[i][j]){
						used.PB(road[n1][n2]);
						// CO<<"dsfs"<<n1<<" "<<n2;
						break;
					}
				}
			}

		}
		CO<<"getting used: ";
		print(used);












		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < n; ++j)
		// 	{
		// 		CO<<g[i][j]<<" ";
		// 	}
		// 	CO<<EL;
		// }

		
	}

	return 0;
}
