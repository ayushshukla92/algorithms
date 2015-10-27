/*
	Directed graph utils
*/


#include <bits/stdc++.h>

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
//--------------------------------utilities end--------------------------------
int n;

void addEdge(unordered_map<int,vector<int> > &graph, int l, int r)
{
	graph[l].PB(r);
}

void addWeight(unordered_map<int,vector<int> > &graph, map<PII, int> &cost, int l, int r,int w)
{
	graph[l].PB(r);
	cost[{l,r}] = w;
}


void dfsVisit(unordered_map<int,vector<int> > &graph,std::vector<int> &visited ,int s, stack<int> &ms)
{
	visited[s] = 1;
	for(auto child : graph[s])
	{
		if(visited[child]==0)
			dfsVisit(graph,visited,child,ms);
		else if(visited[child]==1)
		{
			cout<<"cycle exist!";
		}
	}
	ms.push(s);
	visited[s] = 2;
}

void topologicalSort(unordered_map<int,vector<int> > &graph,int s)
{
	stack<int> ms;
	vector<int> visited(n,0);
	for(int i = 0;i < n; i++)
	{
		if(!visited[i])
			dfsVisit(graph,visited,i,ms);
	}
	while(!ms.empty()){
		cout<<ms.top()<<' ';
		ms.pop();
	}

}


void bfs(unordered_map<int,std::vector<int> >&graph, int s)
{
	queue<int> mq;
	std::vector<bool> visited(n,false);
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
			else 
			{

				cout<<"cycle exist!";
			}
		}

	}

}

void dijkstra(unordered_map<int,std::vector<int> > &graph, map<PII , int> cost, int s)
{
	VI dist(n,inf);
	VI marked(n,false);
	VI parent(n,-1);

	dist[s] = 0;
	for(int i = 0; i < n; i++)
	{

		int min=inf, cur=0;
		for(int i = 0;i<n;i++){	
			if(min>dist[i] && !marked[i])
			{
				min = dist[i];
				cur = i;
			}
		 }
		 marked[cur] = true;	

		for(auto child : graph[cur])
		{
			if(dist[child] > dist[cur] + cost[{cur,child}]){
				dist[child] = dist[cur] + cost[{cur,child}];
				parent[child] = cur;
			}
		}
	}
	print(dist);
	print(parent);
	}

void bellmanFord(unordered_map<int,std::vector<int> > &graph, map<PII , int> cost, int s)
{
	int n = graph.size();
	VI dist(n,inf);
	VI parent(n,-1);

	dist[s] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int cur = 0;cur<n;cur++)
		{	
			for(auto child : graph[cur])
			{
				if(dist[child] > dist[cur] + cost[{cur,child}]){
					dist[child] = dist[cur] + cost[{cur,child}];
					parent[child] = cur;
				}
			}
		}
	}
	print(dist);
}

void unusedPath(unordered_map<int,std::vector<int> > &graph){
	
}
int main()
{
	unordered_map<int,std::vector<int> > graph;
	map<PII , int> cost;
	n = 6;
	addEdge(graph,5,0);
	addEdge(graph,4,0);
	addEdge(graph,5,2);
	addEdge(graph,4,1);
	addEdge(graph,2,3);
	addEdge(graph,3,1);

	topologicalSort(graph,5);

	//bellmanFord(graph,cost,0);
	return 0;
}
