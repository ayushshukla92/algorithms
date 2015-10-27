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

#define inf 0x7fffffff

#define MP make_pair
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define EL endl
#define CO cout

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 
//-----------------------------------------utilities end---------------------------

void print2D(vector< vector<int> > &graph){
	int n = graph.size();
	for(int i=0;i<n;i++)
	{
		for(int num : graph[i])
			cout<<num<<' ';
		cout<<EL;
	}
}

vector< vector<int> > allPairShortestPath(vector< vector<int> > graph)
{
	int n = graph.size();
	for(int k = 0;k<n;k++){
		for(int u = 0;u<n;u++){
			for(int v = 0;v<n;v++){
				if(graph[u][k]!=inf && graph[k][v]!=inf && graph[u][v]>graph[u][k]+graph[k][v]){
					// CO<<"rhs="<<graph[u][k]+graph[k][v]<<EL;
					graph[u][v] = graph[u][k]+graph[k][v];
				}
			}
		}
	}
	return graph;
}

void getUnusedPath(vector< vector<int> > &graph,vector< vector<int> > &modGraph,std::vector<PII> &edges)
{
	int n = graph.size();
	set<pair<int,int>> ms;
 	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			for(auto edge : edges)
				{
					int u = edge.first;
					int v = edge.second;
					if(graph[i][j]==inf || graph[i][u]==inf || graph[u][v]==inf || graph[v][j]==inf || ms.find({u,v})!=ms.end())
						continue;
					cout<<"i="<<i<<"j="<<j<<"u="<<u<<"v="<<v<<EL;
					if(modGraph[i][j]==graph[i][u]+graph[u][v]+graph[v][j]){
						cout<<graph[i][j]<<' '<<graph[i][u]<<' '<<graph[u][v]<<' '<<graph[v][j]<<EL;
						CO<<"--------------------------------------------"<<EL;
						ms.insert({u,v});
					}
				}
		}
	}
	set<PII>::iterator it;
	for(it = ms.begin();it!=ms.end();it++){
		cout<<it->first<<' '<<it->second<<EL;
	}
}

int main()
{
	int n;
	cin>>n;
	vector< vector<int> > graph(n,vector<int>(n,inf));
	for(int i=0;i<n;i++) graph[i][i]= 0;
	// print(graph[0]);
	int m;
	cin>>m;
	std::vector<pair<int,int> > edges;
	while(m--)
	{
		int l,r,w;
		cin>>l>>r>>w;
		edges.PB({l,r});
		graph[l][r] = w;
	}
	print2D(graph);
	CO<<"-------------------"<<EL;
	 vector< vector<int> > modGraph= allPairShortestPath(graph);
	getUnusedPath(graph,modGraph,edges);
	print2D(modGraph);




	return 0;
}
