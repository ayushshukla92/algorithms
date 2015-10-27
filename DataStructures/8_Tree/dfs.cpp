/*
Program to find cycles in undirected graph
*/


#include <iostream>
#include <vector>
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
	adj[j]->neighbors.push_back(adj[i]);   
}

void trace(int i, int j,vector<graphNode*> adj)
{
	
	while(j!=i){
	
		cout<<j<<"->";
		if(adj[j]->par){

			j= adj[j]->par->val;
	
		}
		else{
			
			break;
		}
	
	}
	cout<<i<<endl;
}

void visit(vector<graphNode*> adj, int val, vector<bool>& visited)
{
	
	visited[val] = true;
	for(graphNode* node : adj[val]->neighbors)
	{
		if(!visited[node->val])
		{
			node->par = adj[val];
			visit(adj,node->val,visited);
		}
		else if(adj[val]->par!=NULL && node->val != adj[val]->par->val)
		{
		
			trace(node->val,val,adj);
		}

	}
}

void hasCycle(vector<graphNode*> adj)
{
	vector<bool> visited(adj.size(),false);
	for(graphNode* node : adj)
	{
		if(!visited[node->val]){
			visit(adj,node->val,visited);
		}
	}																	
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