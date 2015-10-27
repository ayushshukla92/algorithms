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
#define MAX 10000007
template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

int dijkstra(unordered_map<int, std::vector<PII> > &graph, int nn1, int nn2){
	int n = graph.size();
	VI dist(n+1,MAX);
	VB marked(n+1,false);
	dist[nn1] = 0;
	REP(i,n){
		int min = MAX,ind = 0;
		FOR(j,1,n){
			if(min>dist[j] && !marked[j]){
				min = dist[j];
				ind = j;
			}
		}

		marked[ind]  = true;

		for(auto it : graph[ind]){
			int k = it.F;

			if(dist[k] > dist[ind] + it.S){
				dist[k] = dist[ind] + it.S;
			}
		}


	}
	return dist[nn2];

}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n;
		unordered_map<int, unordered_map<int,int> > ston;
		unordered_map<int, PII> ntos;
		unordered_map<int, std::vector<PII> > graph;
		// unordered_map<int, unordered_map<int,int> > times;



		SD(n);
		VI w(n);
		int nn = 1;
		for (int i = 0; i < n; ++i)
		{
			int tot;
			SD(tot);SD(w[i]);

			// mml(graph,nn,tot);
			for (int j = 0; j < tot-1; ++j)
			{

				int temp;
				SD(temp);

				ston[i][j] = nn + j;

				graph[nn+j].PB({nn+j+1,temp});
				graph[nn+j+1].PB({nn+j,temp});
				ntos[nn+j] = {i,j};




			}
			ston[i][tot-1] = nn + tot-1;
			ntos[nn+tot-1] = {i,tot-1};

			nn = nn+tot;
		}
		int m;
		SD(m);
		for (int i = 0; i < m; ++i)
		{
			int a,b,c,d,ti;
			SD(a);SD(b);SD(c);SD(d);SD(ti);
			a--;b--;c--;d--;
			int nn1 = ston[a][b],nn2 = ston[c][d];
			graph[nn1].PB({nn2,ti+w[c]}); 
			graph[nn2].PB({nn1,ti+w[a]}); 
		}
		int q;
		SD(q);
		while(q--){
			int a,b,c,d;
			SD(a);SD(b);SD(c);SD(d);
			a--;b--;c--;d--;
			int nn1 = ston[a][b],nn2 = ston[c][d];
			int res = dijkstra(graph,nn1,nn2);
			res = res + w[a] ;
			CO<<res<<EL;
		}
		
	}

	return 0;
}
