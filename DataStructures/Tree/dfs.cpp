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
#define MAX 100001
template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

void dijkstra(unordered_map<int, unordered_map<int,int> > &graph, int n, int s){
	// int n = graph.size();
	VI dist(n+1,MAX);
	VB marked(n+1,false);
	dist[s] = 0;
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

			if(dist[k] > dist[ind] + graph[ind][k]){
				dist[k] = dist[ind] + graph[ind][k];
			}
		}


	}
	print(dist);

}

int dijkstra1(unordered_map<int, std::vector<PII> > &graph, int nn1, int nn2){
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

int main()
{
	unordered_map<int, unordered_map<int,int> > graph;

	graph[1][2] = 2;
	graph[2][4] = 1;
	graph[1][4] = 5;
	graph[1][3] = 6;
	graph[2][3] = 1;
	graph[3][4] = 2;
	// CO<<graph.size();
	dijkstra(graph,4,1);

	return 0;
}
