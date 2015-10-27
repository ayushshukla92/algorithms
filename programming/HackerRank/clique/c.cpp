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

void addEdge(unordered_map<int,vector<int> > &graph, int l, int r)
{
	graph[l].PB(r);
	graph[r].PB(l);
}

bool isBlack(unordered_map<int,std::vector<int> >&graph, int s,int e,VI &color)
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
		mq.pop();
		if(cur==e){

			while(e!=-1){
				if(color[e]==1)
					return true;
	
				e = parent[e];
			}
			return false;
		}
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

			//	cout<<"cycle exist!";
			}
		}

	}
	return false;

}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		unordered_map<int,std::vector<int> > graph;
		VI color;
		VI white;
		for(int i= 0;i<n;i++){
			int temp;
			cin>>temp;
			color.PB(temp);
			if(temp == 0)
				white.PB(i);
		}

		for(int i= 0;i<n-1;i++){
			int l,r;
			cin>>l>>r;
			l--;r--;
			addEdge(graph,l,r);

		}
		// CO<<graph[0].size()<<'&'<<EL;
		// CO<<graph[1].size()<<'&'<<EL;
		// CO<<graph[2].size()<<'&'<<EL;

		if(white.size()<=2)
			cout<<0<<endl;
		else{
			int m = white.size();
			int res = 0;
			for(int i = 0;i<m-2;i++)
			{
				for(int j = i+1;j<m-1;j++){
					for(int k = j+1;k<m;k++){
						if(isBlack(graph,white[i],white[j],color)&&
						isBlack(graph,white[j],white[k],color)&&
						isBlack(graph,white[i],white[k],color))
						{
							res++;
						}
					}
				}
			}
			cout<<res<<EL;
		}




	}
	return 0;
}
