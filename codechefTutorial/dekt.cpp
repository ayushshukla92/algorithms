#include <bits/stdc++.h>

using namespace std;

int solve(vector< vector<int> > graph, int cur, int &gmax, vector<bool> &visited){
	visited[cur] = true;

	if(graph[cur].size()==0)
		return 0;

	int max1 = 0,max2 = 0,temp = -1;

	for(int i : graph[cur]){
		if(visited[i])
			continue;	
		int next= solve(graph,i,gmax,visited);
		max1 = max(max1,next);
		if(next>max1)
		{
			max1 = next;
			max2 = max1;
		}
		else if(next>max2)
			max2 = next;
	}
	gmax = max(gmax,max1+max2+2);
	return 1 + max(max1,max2);


}

int main()
{
	int n;
	cin>>n;
	vector< vector<int> > graph(n);
	std::vector<bool> visited(n,false);
	n--;
	while(n--)
	{
		int l,r;
		cin>>l>>r;
		graph[l-1].push_back(r-1);
	}
	int gmax = 1;
	solve(graph,0,gmax,visited);
	cout<<gmax<<endl;
		
	return 0;

}