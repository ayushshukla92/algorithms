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
// typedef unordered_map<int,vector<int> > VP;
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
#define MAX 1000001

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 




void solve(unordered_map< int, unordered_map<int,VI> > &graph,int dest,int s_t,int n )
{
	VI dist(n+1,MAX);
	VI marked(n+1,false);
	VI stamp(n+1,-1);
	dist[1] = 0;
	stamp[1] = s_t;
	for (int i = 0; i < n; ++i)
	{
		int min = MAX,cur=0;
		// int j;
		REP(j, n){
			if(min > dist[j] && !marked[j]){
				min = dist[j];
				cur = j;
			}
		}
		marked[cur] = true;

		for(auto it : graph[cur]){
			int k = it.F;
			int curT = stamp[cur];
			if (dist[k] > dist[cur] + it.S[curT])
			{
				dist[k] = dist[cur] + it.S[curT];
				stamp[k] = stamp[cur] + it.S[curT];
				stamp[k] = stamp[k]%24;

			}
		}

	}
	if(dist[dest]==MAX)
		CO<<"-1"<<" ";
	else
		CO<<dist[dest]<<" ";

}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,m,k;
		cin>>n>>m>>k;
		unordered_map< int, unordered_map<int,VI> > graph;
		while(m--){
			int l,r; //edge from l to r
			cin>>l>>r;
			int tm = 24;

			while(tm--){
				int temp;
				cin>>temp;
				graph[l][r].PB(temp);
				graph[r][l].PB(temp);
			}


		}
		while(k--){
			int dest,s_time;
			cin>>dest>>s_time;
			solve(graph,dest,s_time,n);
		}
		CO<<EL;

	}

	return 0;
}
