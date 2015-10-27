/*
Program to find cycles in undirected graph
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct graphNode 
{
	int val;
	graphNode* par;
	vector<graphNode *> neighbors;
};

void printV(vector<int> &v)
{
	for(int i: v)
		cout<<i<<' ';
	cout<<endl;
}

vector<graphNode *>  makeGraph(int v)
{
	vector<graphNode *> res;
	for(int i=0;i<v;i++)
	{
		graphNode* node = new graphNode;
		node->val = i;
		node->par = NULL;
		res.push_back(node);
	}
	return res;
}
void addEdge(vector<graphNode *> adj,int i, int j)
{
	adj[i]->neighbors.push_back(adj[j]);
}

void trace(stack<int> recStack, int start)
{
	cout<<start<<"->";
	while(recStack.top()!=start){
		cout<<recStack.top()<<"->";
		recStack.pop();
	}
	cout<<start<<endl;
}

bool inRecStack(int val, stack<int> ms)
{
	while(!ms.empty())
	{
		if(val = ms.top())
			return true;
		ms.pop();
	}
	return false;
}

void visit(vector<graphNode*> adj, int val, vector<bool>& visited,stack<int>& recStack)
{
	
	visited[val] = true;
	recStack.push(val);

	for(graphNode* node : adj[val]->neighbors)
	{
		if(!visited[node->val])
		{
			node->par = adj[val];
			visit(adj,node->val,visited,recStack);
		}
		else if(inRecStack(node->val,recStack))
		{
			cout<<"cycle found\n";
			trace(recStack, node->val);		
		}

	}
	recStack.pop();
}

void hasCycle(vector<graphNode*> adj)
{
	vector<bool> visited(adj.size(),false);
	stack<int> recStack;
	for(graphNode* node : adj)
	{
		if(!visited[node->val]){	
			visit(adj,node->val,visited,recStack);
		}
	}																	
	return;
}

int main()
{
	vector<graphNode *> adj = makeGraph(4);
	addEdge(adj,0,1);
	addEdge(adj,0,2);
	// addEdge(adj,1,2);
	addEdge(adj,2,0);
	addEdge(adj,2,3);
	addEdge(adj,3,3);

	hasCycle(adj);		
	return 0;
}