#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct graphNode 
{
	int val;
	vector<graphNode *> neighbors;
};

void printS(stack<int> &v)
{
	while(!v.empty()){
		int i = v.top();
		cout<<i<<' ';
		v.pop();
	}
	cout<<endl;
}

vector<graphNode *>  makeGraph(int v)
{
	vector<graphNode *> res;
	for(int i=0;i<v;i++)
	{
		graphNode* node = new graphNode;
		node->val = i;
		res.push_back(node);
	}
	return res;
}
void addEdge(vector<graphNode *> adj,int i, int j)
{
	adj[i]->neighbors.push_back(adj[j]);
	//adj[j]->neighbors.push_back(adj[i]);
}

void visit(vector<graphNode*> adj, int val, vector<bool>& visited, stack<int> trace)
{
	visited[val] = true;
	trace.push(val);
	for(graphNode* node : adj[val]->neighbors)
	{
		if(visited[node->val])
		{
			cout<<"cycle found"<<endl;
			printS(trace);
			return;
		}
		visit(adj,node->val,visited,trace);
	}
	trace.pop();
}

void hasCycle(vector<graphNode*> adj)
{
	vector<bool> visited(adj.size(),false);
	stack<int> trace;
	for(graphNode* node : adj)
	{
		if(!visited[node->val]){
			visit(adj,node->val,visited,trace);
		}
	}																	//dfs
	return;
}

int main()
{
	vector<graphNode *> adj = makeGraph(5);
	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,0,3);
	addEdge(adj,3,4);
	addEdge(adj,4,0);

	hasCycle(adj);		
	return 0;
}