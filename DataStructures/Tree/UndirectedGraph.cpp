/*
	Undirected graph utils
*/


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

template <typename T>
 void print(vector<T> &v) 
{ 
    for(T t : v){
    	cout<<t<<' ';
    }
    CO<<EL;
} 

template <typename T>
 void printPair(T a, T b) 
{ 
	CO<<a<<' '<<b;
    CO<<EL;
} 


void addEdge(unordered_map<int,vector<int> > &graph, int l, int r)
{
	graph[l].PB(r);
	graph[r].PB(l);
}

void dfsVisit(unordered_map<int,vector<int> > &graph,std::vector<int> &visited ,int s,int p)
{
	visited[s] = 1;
	cout<<s<<' ';
	for(auto child : graph[s])
	{
		if(visited[child]==0)
			dfsVisit(graph,visited,child,s);
		else if(visited[child]==1 && child!=p)
		{
			cout<<"cycle exist!";
		}
	}
	visited[s] = 2;
}

void dfs(unordered_map<int,vector<int> > &graph,int s)
{
	int n = graph.size();
	vector<int> visited(n,0);
	for(int i = 0;i < n; i++)
	{
		if(!visited[i])
			dfsVisit(graph,visited,i,i);
	}

}

void bfs(unordered_map<int,std::vector<int> >&graph, int s)
{
	queue<int> mq;
	std::vector<bool> visited(graph.size(),false);
	unordered_map<int,int> parent;
	mq.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!mq.empty())
	{
		int cur = mq.front();
		cout<<cur<<' ';
		mq.pop();
		for(auto child : graph[cur])
		{
			if(!visited[child])
			{
				visited[child] = true;
				mq.push(child);
				parent[child] = cur;
			}
			else if(parent[cur]!=child)
			{

				cout<<"cycle exist!";
			}
		}

	}

}

int main()
{
	unordered_map<int,vector<int> > graph;
	addEdge(graph,0,1);
	addEdge(graph,0,3);
	addEdge(graph,2,0);
	addEdge(graph,0,4);
	addEdge(graph,1,5);
	addEdge(graph,2,6);
	addEdge(graph,5,6);
	// addEdge(graph,3,0);

	// addEdge(graph,4,0);
	// addEdge(graph,5,4);
	// addEdge(graph,5,0);

	bfs(graph,0);


	return 0;
}
