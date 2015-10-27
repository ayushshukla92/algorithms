#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstring>
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

using namespace std;

typedef pair <int, int> PII;
typedef pair <int, double> PID;
typedef pair <double, double> PDD;
typedef vector <int> VI;
typedef vector <double> VD;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout
#define inf 0x7fffffff

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

struct edge{
	int dest,timee,num;	
};

void mark(vector< vector<edge> > graph,int s,int n)
{
	vector<int> dist(n,inf);
	dist[s] = 0;
	for(edge i : graph[s])
		dist[i.dest] = i.timee;

	for(int i = 0;i<n;i++)
	{
		int minE = min_element(dist.begin(),dist.end()) - dist.begin();
		//markEdge(s,minE);
		for(edge child  : graph[minE]){

			int col=0;
			for(edge i : graph[minE]){
				if(graph[minE][i].dest==child.dest)
					col = i;
			}
			// if(dist[child.dest]>dist[minE]+graph[minE][col])
			// 	dist[child.dest]=dist[minE]+graph[minE][col];
		}

	//change s
	}
}

int main() {
	int Tcases;

	cin >> Tcases;

	for (int tc = 1; tc <= Tcases; tc++) {
		cout << "Case #" << tc << ": ";
		int n,m;
		cin>>n>>m;
		vector< vector<edge> > graph(n);
		int temp=0;
		while(temp<m){
			int start,dest,timee;
			cin>>start>>dest>>timee;
			edge e;
			e.num = temp;
			e.dest  = dest;
			e.timee = timee;
			graph[start].push_back(e);
			edge e1;
			e1.num = temp;
			e1.dest  = start;
			e1.timee = timee;
			graph[dest].push_back(e1);
			temp++;


			
		}

	return 0;
		}
}
